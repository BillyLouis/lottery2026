package data

import (
	"encoding/csv"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

type Draw struct {
	Date  string
	Balls []int
	// optional: for powerball red ball stored separately as last element
}

// LoadDraws loads CSV with either fantasy5 (date,b1,b2,b3,b4,b5) or powerball (date,w1,w2,w3,w4,w5,red)
// It tolerates optional header.
func LoadDraws(path string) ([]Draw, error) {
	f, err := os.Open(path)
	if err != nil {
		return nil, err
	}
	defer f.Close()
	r := csv.NewReader(f)
	var rows [][]string
	for {
		rec, err := r.Read()
		if err == io.EOF {
			break
		}
		if err != nil {
			return nil, err
		}
		// skip empty lines
		empty := true
		for _, c := range rec {
			if strings.TrimSpace(c) != "" {
				empty = false
				break
			}
		}
		if empty {
			continue
		}
		rows = append(rows, rec)
	}
	if len(rows) == 0 {
		return nil, fmt.Errorf("no rows")
	}
	// check if header present: detect non-numeric in first data col (after date)
	start := 0
	if len(rows[0]) > 1 {
		if _, err := strconv.Atoi(strings.TrimSpace(rows[0][1])); err != nil {
			start = 1 // skip header
		}
	}
	var draws []Draw
	for i := start; i < len(rows); i++ {
		row := rows[i]
		if len(row) < 2 {
			continue
		}
		date := strings.TrimSpace(row[0])
		balls := []int{}
		for j := 1; j < len(row); j++ {
			cell := strings.TrimSpace(row[j])
			if cell == "" {
				continue
			}
			n, err := strconv.Atoi(cell)
			if err != nil {
				return nil, err
			}
			balls = append(balls, n)
		}
		draws = append(draws, Draw{Date: date, Balls: balls})
	}
	return draws, nil
}
