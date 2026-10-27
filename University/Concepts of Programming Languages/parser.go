package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	fmt.Print("Hello, please enter a phrase!:")
	in := bufio.NewReader(os.Stdin)
	phrase, _ := in.ReadString('\n')
	parser(scanner(phrase))
}

func scanner(phrase string) ([]string, bool) {
	error := false
	invalidUnits := []string{}
	arr := strings.Fields(phrase)
	for _, x := range arr {
		for _, y := range x {
			switch y {
			case '0', '1', '2', '3', '4', '5', '6', '7', '8', '9':
			case '+', '-', '*', '/':
			default:
				invalidUnits = append(invalidUnits, string(y))
				error = true
			}
		}
	}
	if error {
		fmt.Printf("Lexical Error! %s contains invalid lexical units ", arr)
		for _, unit := range invalidUnits {
			fmt.Printf("[%s], ", unit)
		}
	}
	return arr, error
}

func parser(phrase []string, error bool) {
	if error {
		return
	}

}
