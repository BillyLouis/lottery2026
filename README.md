# lottery2026
Sample code for lottery prediction
## ################################
**DISCLAIMER:** Not a real lottery predictor, It is simply used as base model for a bigger project. in the bigger project, it helps with a prediction of 2 to 4 numbers out of 6.
Use at your own risk.
## ################################
## ################################


![alt text](images/2022_August15_PBall_IMG_3039.jpg)


![alt text](images/<2022_June15_PBall_IMG_2871 - use.jpg>)


![alt text](images/2022_March30_SuperLotto_IMG_2798.png)


### Preface
```shell
# lottery2026

Go + cgo starter repo for lottery forecasting:
- California Fantasy5 (1-39)
- Powerball (white 1-69, red 1-26)

Requirements:
- Go 1.21+
- C toolchain (gcc/clang)
- Python3 (for CSV reverse utility)

Build:
  CGO_ENABLED=1 go build ./...

Run dry:
  go run ./cmd/lottery-run -game fantasy5 -mode test

Predict N draws ahead:
For example if draw is daily, then, the newest in the csv is April 9th
for the 3 output will be for April 10th, April 11th and April 12th.
  go run ./cmd/lottery-run -game fantasy5 -predict 3

  CGO_ENABLED=1 go run ./cmd/lottery-run -game fantasy5 -mode simulate -iters 200000

Predict for a date:
  # If you know how many draws from most recent data your target is
  go run ./cmd/lottery-run -game fantasy5 -predict 3

Reverse a newest-to-oldest CSV:
  python3 internal/data/csv_reverse.py input_newest.csv data/fantasy5_draws.csv --has-header

If -mode simulate it will also run Monte Carlo counts for more context.
-----------------------------------------------------------------------------
NEW COMPILATION:
more seeds integrations:
-----------------------------------------------------------------------------
# install OpenSSL:
$ sudo apt update
$ sudo apt install -y build-essential pkg-config libssl-dev

# Compile 1:
CGO_ENABLED=1 go run main.go   -game=fantasy5   -mode=simulate   -predict=1   -iters=200000   -seed-mode=sha256   -seed-base=123456789   -date=2024-05-05

CGO_ENABLED=1 go run main.go   -game=fantasy5   -mode=simulate   -predict=3   -iters=4000   -seed-mode=primejump   -seed-base=123456789   -date=2024-05-04

# or run the shell script: in scripts/run_experiments.sh
# Compile 2:
$ ./run_experiments.sh

-----------------------------------------------------------------------------

```  

## ##############################################
## ##############################################
### TREE:
```shell
lottery2026/
├─ go.mod
├─ README.md
├─ cmd/
│  └─ lottery-run/
│     └─ main.go
├─ internal/
│  ├─ data/
│  │  ├─ loader.go
│  │  └─ csv_reverse.py
│  ├─ features/
│  │  └─ features.go
│  ├─ model/
│  │  ├─ ensemble.go
│  │  ├─ freq_model.go
│  │  ├─ markov.go
│  │  └─ montecarlo_model.go
│  └─ sim/
│     ├─ sim_c.go
│     └─ sim_wrapper.go
├─ data/
│  ├─ fantasy5_draws.csv    (your Fantasy5 data)
│  └─ powerball_draws.csv   (your Powerball data)
└─ scripts/
   └─ run_experiments.sh


```
## ##############################################
## ##############################################
### Directories:
#### internal/data/csv_reverse.py
```shell
# It preserves header (if present) and reverses the data rows.
Quick CSV reverse script because the csv files are newest→oldest and the code needs oldest→newest order

# If the CSV has header row (e.g., date,b1,b2,b3,b4,b5)
such as:
2016-01-01,3,12,18,24,36
2016-01-02,5,9,14,27,31
...
2025-12-31,7,11,22,25,33

$ python3 internal/data/csv_reverse.py your_newest_first_fantasy5.csv data/fantasy5_draws.csv --has-header

# If no header
$ python3 internal/data/csv_reverse.py your_newest_first_fantasy5.csv data/fantasy5_draws.csv

```
  

## ##############################################
#### internal/model/montecarlo_model.go
```shell
This model uses the cgo-accelerated Monte Carlo to generate counts, then returns top numbers.
```

## ##############################################
#### internal/model/montecarlo_model.go
```shell
This model uses the cgo-accelerated Monte Carlo to generate counts, then returns top numbers.
```

## ##############################################
#### internal/sim/sim_c.go (cgo + high-performance C Monte Carlo)
```shell
This is the heart of the performance piece. Save as internal/sim/sim_c.go
```


## ##############################################
## ##############################################

## Authors
- [Billy Louis](): Lottery soup in Golang and C/C++.


## Badges
Hardware Team: [NSAL.com](https://NSAL.com/)

[![NSA License](https://img.shields.io/badge/License-NSAL-green.svg)](https://choosealicense.com/licenses/nsal/)
