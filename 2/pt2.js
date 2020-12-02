const fs = require('fs')

const file = fs.readFileSync('./input.txt', 'utf8')

const lines = file.split('\n')

let validPasswords = 0

const checkRule = (rule, pass) => {
  if (!rule || !pass) return false

  let valid = false

  const [ indices, letter ] = rule.split(' ')
  const [ first, second ] = indices.split('-').map(i => parseInt(i))

  if (pass[first] === letter && pass[second] !== letter) {
    valid = true
  } else if (pass[first] !== letter && pass[second] === letter) {
    valid = true
  }
  
  return valid
}

lines.map(line => {
  const [rule, pass]  = line.split(':')

  if (checkRule(rule, pass)) {
    validPasswords++
  }
})

console.log('Answer: ', validPasswords)

