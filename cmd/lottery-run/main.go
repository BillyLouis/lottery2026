package main

import (
	"flag"
	"fmt"
	"log"
	"path/filepath"
	"time"

	"github.com/BillyLouis/lottery2026/internal/data"
	"github.com/BillyLouis/lottery2026/internal/features"
	"github.com/BillyLouis/lottery2026/internal/model"
	"github.com/BillyLouis/lottery2026/internal/sim"
)

const (
	Version   = "1.1.0"
	data_path = "/home/ubuntu_dock/go/src/github.com/BillyLouis/lottery2026/data"
	expecting = `--------------------------------
	Predict 1: 	WED	04/03/24	04-16-19-35-38
	Predict 2:	THU	04/04/24	04-11-19-23-26
	Predict 3:	FRI	04/05/24	01-25-27-28-36
	-------------------------`
)

func main() {
	// --- CLI Flags ---
	game := flag.String("game", "fantasy5", "game: fantasy5|powerball")
	mode := flag.String("mode", "test", "mode: test|simulate|play")
	predict := flag.Int("predict", 1, "predict N draws ahead (1 = next draw)")
	iters := flag.Int("iters", 200000, "monte carlo iterations for simulate mode")
	dataPath := flag.String("data", "", "override data file path")
	seedModeFlag := flag.String("seed-mode", "pcg", "seed mode: lcg|fibonacci|primejump|lehmer|pcg|weyl|goldenhash|sha256")
	baseSeed := flag.Uint64("seed-base", 123456789, "base seed (deterministic) used by seed generators")
	dateStr := flag.String("date", "", "date string used for SHA256 seed mode (format flexible, e.g. 2026-04-13)")
	flag.Parse()

	// --- Seed Mode Mapping ---
	seedMap := map[string]int{
		"lcg":        0,
		"fibonacci":  1,
		"primejump":  2,
		"lehmer":     3,
		"pcg":        4,
		"weyl":       5,
		"goldenhash": 6,
		"sha256":     7,
	}
	seedMode, ok := seedMap[*seedModeFlag]
	if !ok {
		log.Fatalf("unknown seed-mode: %s", *seedModeFlag)
	}

	// --- Determine Data File ---
	var defaultPath string
	switch *game {
	case "fantasy5":
		defaultPath = filepath.Join(data_path, "fantasy5_draws.csv")
	case "powerball":
		defaultPath = filepath.Join("data", "powerball_draws.csv")
	default:
		log.Fatalf("unknown game: %s", *game)
	}
	if *dataPath != "" {
		defaultPath = *dataPath
	}

	// --- Load Draws ---
	draws, err := data.LoadDraws(defaultPath)
	if err != nil {
		log.Fatalf("load draws: %v", err)
	}
	if len(draws) == 0 {
		log.Fatalf("no draws in %s", defaultPath)
	}

	// --- Extract Features ---
	feats := features.ExtractAll(draws)

	// --- Create Simulator ---
	simulator := sim.NewSimulator()

	// --- Create Monte Carlo Model with Seed ---
	mc := model.NewMonteCarloModel(feats, simulator, seedMode)

	// --- Build Ensemble ---
	ens := model.NewEnsemble()
	ens.AddModel(model.NewFrequencyModel(feats)) // frequency model
	ens.AddModel(mc)                             // Monte Carlo model

	// --- Simulation Mode ---
	if *mode == "simulate" {
		iterIndex := uint64(*predict)
		gameName := *game
		dateForSeed := *dateStr
		if dateForSeed == "" {
			dateForSeed = time.Now().Format("2006-01-02")
		}

		fmt.Printf("Running Monte Carlo: iters=%d, numbersRange=%d, pickK=%d, seedMode=%s, base=%d, game=%s, date=%s, iterIndex=%d\n",
			*iters, feats.NumbersRange, feats.PickK(), *seedModeFlag, *baseSeed, gameName, dateForSeed, iterIndex)

		//counts := sim.RunMonteC(*iters, feats.NumbersRange, feats.PickK(), *baseSeed, seedMode, gameName, dateForSeed, iterIndex)
		// Print top counts (first 40 or numbersRange)
		limit := feats.NumbersRange
		if limit > 40 {
			limit = 40
		}
		for i := 0; i < limit; i++ {
			//fmt.Printf("%2d -> %d\n", i+1, counts[i])
		}
		//return
	}

	// --- Default Ensemble Prediction ---
	fmt.Printf("Game: %s  Loaded draws: %d\n", *game, len(draws))
	pred := ens.PredictTopK(int(feats.PickK()))
	fmt.Println("Top candidates (voting):", pred)
	fmt.Println("Expected format:")
	fmt.Println(expecting)
	fmt.Println(" ")

	// Call the Eigen predictor
	fmt.Println("\n\n\n---------------------------------------")
	log.Printf("Now Running Eigen predictor...")
	simulator.RunPredictor()
	fmt.Println("---------------------------------------")

}
