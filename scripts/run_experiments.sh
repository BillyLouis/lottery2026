#!/bin/bash
# -------------------------------------------------------------------
# Script: run_lottery.sh
# Purpose: Compile and run lottery2026 main.go with cgo and Monte Carlo
# Usage: ./run_lottery.sh [game] [mode] [predict] [iters] [seed-mode] [seed-base] [date]
# Example:
# ./run_lottery.sh fantasy5 simulate 1 200000 sha256 123456789 2026-04-13
#
# Game option: fantasy5 or powerball (or any other valid game your main.go switch supports)
# Seed option: "lcg", "fibonacci", "primejump", "lehmer", "pcg", "weyl", "goldenhash", "sha256"
# -------------------------------------------------------------------

# ----------- Default values if no arguments provided --------------
GAME=${1:-fantasy5}
MODE=${2:-simulate}
PREDICT=${3:-1}
ITERS=${4:-200000}
SEED_MODE=${5:-sha256}
SEED_BASE=${6:-123456789}
DATE=${7:-$(date +%Y-%m-%d)}

# ----------- Environment variables for cgo ------------------------
export CGO_ENABLED=1
export GOOS=linux
export GOARCH=amd64

# ----------- Build the binary --------------------------------------
echo "Compiling lottery2026..."
go build -o lottery2026  ../cmd/lottery-run/main.go
if [ $? -ne 0 ]; then
    echo "Build failed!"
    exit 1
fi

# ----------- Run the binary ----------------------------------------
echo "Running lottery2026 with:"
echo "  Game: $GAME"
echo "  Mode: $MODE"
echo "  Predict: $PREDICT"
echo "  Iterations: $ITERS"
echo "  Seed mode: $SEED_MODE"
echo "  Base seed: $SEED_BASE"
echo "  Date: $DATE"
echo "---------------------------------------------------------------"

./lottery2026 \
  -game=$GAME \
  -mode=$MODE \
  -predict=$PREDICT \
  -iters=$ITERS \
  -seed-mode=$SEED_MODE \
  -seed-base=$SEED_BASE \
  -date=$DATE
if [ $? -ne 0 ]; then
    echo "Execution failed!"
    exit 1
fi
echo "Simulation for $GAME with $ITERS iterations completed."
