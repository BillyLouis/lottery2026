package model

import (
	"sort"
)

type Predictor interface {
	Predict() []int
	Name() string
}

type Ensemble struct {
	models []Predictor
}

func NewEnsemble() *Ensemble             { return &Ensemble{} }
func (e *Ensemble) AddModel(p Predictor) { e.models = append(e.models, p) }

func (e *Ensemble) PredictTopK(k int) []int {
	score := make(map[int]float64)
	for _, m := range e.models {
		cands := m.Predict()
		for i, n := range cands {
			score[n] += float64(len(cands) - i) // crude positional weight
		}
	}
	type kv struct {
		n int
		s float64
	}
	var arr []kv
	for n, s := range score {
		arr = append(arr, kv{n, s})
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i].s > arr[j].s })
	out := make([]int, 0, k)
	for i := 0; i < k && i < len(arr); i++ {
		out = append(out, arr[i].n)
	}
	return out
}
func (e *Ensemble) PredictAll() []int { //-- Additionals by agent
	score := make(map[int]float64)
	for _, m := range e.models {
		cands := m.Predict()
		for i, n := range cands {
			score[n] += float64(len(cands) - i) // crude positional weight
		}
	}
	type kv struct {
		n int
		s float64
	}
	var arr []kv
	for n, s := range score {
		arr = append(arr, kv{n, s})
	}
	sort.Slice(arr, func(i, j int) bool { return arr[i].s > arr[j].s })
	out := make([]int, 0, len(arr))
	for i := 0; i < len(arr); i++ {
		out = append(out, arr[i].n)
	}
	return out
}
func (e *Ensemble) ModelNames() []string {
	var names []string
	for _, m := range e.models {
		names = append(names, m.Name())
	}
	return names
}
func (e *Ensemble) ModelCount() int {
	return len(e.models)
}
func (e *Ensemble) ClearModels() {
	e.models = []Predictor{}
}
func (e *Ensemble) GetModels() []Predictor {
	return e.models
}
func (e *Ensemble) SetModels(models []Predictor) {
	e.models = models
}
