const fs = require('fs')

const file = fs.readFileSync('./input.txt', 'utf8')

const lines = file.split('\n')

let validPasswords = 0

const checkRule = (rule, pass) => {
  if (!rule || !pass) return false

  let valid = false

  const [ boundaries, letter ] = rule.split(' ')
  const [ min, max ] = boundaries.split('-').map(b => parseInt(b))

  console.log('rule', rule)
  console.log('min:', min, ', max:', max)
  console.log('letter:', letter)

  let count = 0
  for (let i = 0; i < pass.length; ++i) {
    if (pass[i] === letter) ++count
  }

  if (count >= min && count <= max) {
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

