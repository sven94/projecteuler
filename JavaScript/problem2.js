main();

function main() {
    const limit = 4e6;

    const sequence = getFibSequence(limit);

    let result = 0;
    sequence.forEach(number => {
        if (number % 2 === 0) {
            result += number;
        }
    });

    console.log(`Sum of the even-valued Fibonacci terms below ${limit} = ${result}`);
}

function getFibSequence(limit) {
    let sequence = [1, 2];

    while (true) {
        let nextNumber = sequence[sequence.length - 1] + sequence[sequence.length - 2];

        if (nextNumber < limit) {
            sequence.push(nextNumber);
        } else {
            break;
        }
    }

    return sequence;
}