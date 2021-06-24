main();

function main() {
    const limit = 1000;
    let result = 0;

    for (let i = 1; i < limit; i++) {
        if (isMultiple(i)) {
            result += i;
        }
    }

    console.log(`Sum of all multiples below ${limit} = ${result}`);
}

function isMultiple(number) {
    if (number % 3 === 0 || number % 5 === 0) {
        return true;
    }
}