package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	proceed := true
	for proceed {
		fmt.Print("\nPlease enter a phrase!: ")
		phrase, _ := in.ReadString('\n')
		fmt.Println(parser(phrase))
		fmt.Print("\nWould you like to test another? (Y/n): ")
		phrase, _ = in.ReadString('\n')
		proceed = phrase[0] == 'y' || phrase[0] == '\n'
	}
}

func scanner(phrase string) ([]string, bool) {
	invalidUnits := ""
	arr := strings.Fields(phrase)
	if len(arr) == 0 {
		invalidUnits = " [] "
	}
	for _, x := range arr {
		for _, y := range x {
			switch y {
			case '+', '*', '/', '-':
			default:
				_, err := strconv.Atoi(string(y))

				if err != nil {
					invalidUnits += " [" + string(y) + "],"
				}
			}
		}
	}
	if len(invalidUnits) != 0 {
		arr = []string{("\nLexical Error! [" + strings.Join(arr, " ") + "] contains invalid lexical units" + invalidUnits[:len(invalidUnits)-1])}
	}
	return arr, len(invalidUnits) != 0
}

func parser(phrase string) string {
	scanned, err := scanner(phrase)
	result := strings.Join(scanned, "")
	if !err {
		result = parserRecursive(scanned, 0)
		switch result {
		case "<BUExp>":
			result = "\nMatches! “[" + phrase[:len(phrase)-1] + "]” is a valid BU expression"
		default:
			result = "\nSyntactic Error! “[" + phrase[:len(phrase)-1] + "]” is not a valid BU expression"
		}
	}
	return result
}

func parserRecursive(phrase []string, iter int) string {
	parsed := " "
	for i := len(phrase) - 1; i >= 0; i-- {

		if i == 0 || i == len(phrase)-1 {
			switch phrase[i] {
			case "+", "*", "/":
				return ""
			}
		}

		switch phrase[i] {
		case "+":
			if phrase[i-1] == "<Term>" && phrase[i+1] == "<BUExp>" {
				//println(strings.Join(phrase, " "))
				phrase[i-1], phrase[i], phrase[i+1] = "<BUExp>", "", ""
				i--
			}
		case "*", "/":
			if phrase[i-1] == "<Number>" && phrase[i+1] == "<Term>" {
				//println(strings.Join(phrase, " "))
				phrase[i-1], phrase[i], phrase[i+1] = "<Term>", "", ""
				i--
			}
		case "-":
			if phrase[i+1] == "<Integer>" {
				phrase[i], phrase[i+1] = "-<Integer>", ""
			}
		case "<Integer>", "-<Integer>":
			phrase[i] = "<Number>"
		case "<Number>":
			phrase[i] = "<Term>"
		case "<Term>":
			phrase[i] = "<BUExp>"
		default:
			_, err := strconv.Atoi(phrase[i])
			if err != nil {
				phrase = []string{"Fail"}
				i = -1
			} else {
				if phrase[i][0] == '-' {
					phrase[i] = "-<Integer>"
				} else {
					phrase[i] = "<Integer>"
				}
			}
		}
	}
	phrase = strings.Fields(strings.Join(phrase, " "))
	parsed = strings.Join(phrase, " ")
	//println(parsed)
	if parsed == "<BUExp>" || parsed == "Fail" || parsed == "" {
		return parsed
	}
	return parserRecursive(phrase, 1)
}
