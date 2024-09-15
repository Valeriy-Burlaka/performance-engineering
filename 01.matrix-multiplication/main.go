package main

import (
	// "fmt"
	"math/rand"
	// "time"
)

const n = 4096

// const n = 1024

func main() {
	// UPD.:
	// rand.Seed is deprecated: As of Go 1.20 there is no reason to call Seed with a random value.
	// Programs that call Seed with a known value to get a specific sequence of results should use
	// New(NewSource(seed)) to obtain a local random generator.
	// // Seed the random number generator
	// rand.Seed(time.Now().UnixNano())

	// Prepare matricies
	A := make([][]float64, n)
	B := make([][]float64, n)
	C := make([][]float64, n)

	for i := 0; i < n; i++ {
		A[i] = make([]float64, n)
		B[i] = make([]float64, n)
		C[i] = make([]float64, n)

		for j := 0; j < n; j++ {
			A[i][j] = rand.Float64()
			B[i][j] = rand.Float64()
			C[i][j] = 0
		}
	}

	// Perform matrix multiplication
	multiplyMatrices(A, B, C)
}

func multiplyMatrices(A, B, C [][]float64) {
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				C[i][j] += A[i][k] * B[k][j]
			}
		}
	}
}
