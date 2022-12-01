package main

import (
	"flag"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
  FilePath = flag.String("file", "", "the file to load")
)

func main() {
  flag.Parse()
  if FilePath == nil {
    panic("No file provided")
  }

  f, err := os.ReadFile(*FilePath)
  if err != nil {
    panic(err)
  }

  data := string(f)

  sections := strings.Split(strings.Trim(data, "\n"), "\n\n")
  values := []int{}

  for _, section := range sections {
    nums := strings.Split(section, "\n")
    vals := []int{}
    for _, num := range nums {
      n, err := strconv.Atoi(num)
      if err != nil {
        panic(err)
      }
      vals = append(vals, n)
    }

    var value int
    for k, val := range vals {
      if k == 0 {
        value = val
        continue
      }
      value = value + val
    }

    values = append(values, value)
  }

  _, max := findMinAndMax(values)

  var idx int
  for k, v := range values {
    if v == max {
      idx = k
    }
  }

  fmt.Printf("elf %v is carrying the most, with %v calories", idx + 1, max)
}

func findMinAndMax(a []int) (min int, max int) {
	min = a[0]
	max = a[0]

	for _, value := range a {
		if value < min {
			min = value
		}
		if value > max {
			max = value
		}
	}

	return min, max
}
