package main

import (
	"flag"
	"fmt"
	"os"
	"sort"
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

  one, two, three := findTop3Max(values)

  fmt.Printf("%v calories", one + two + three)
}

func findTop3Max(a []int) (one int, two int, three int) {
  sort.Ints(a)
  length := len(a)

  one = a[length - 1]
  two = a[length - 2]
  three = a[length - 3]

	return
}
