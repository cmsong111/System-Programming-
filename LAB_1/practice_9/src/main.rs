use std::io;
use rand::Rng;

fn main() {
    let rows: usize;
    let cols: usize;

    println!("Enter the number of rows: ");
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    rows = input.trim().parse().expect("Invalid input");

    println!("Enter the number of columns: ");
    input.clear();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    cols = input.trim().parse().expect("Invalid input");

    let mut matrix1 = Vec::with_capacity(rows);
    let mut matrix2 = Vec::with_capacity(rows);

    for _ in 0..rows {
        let mut row1 = Vec::with_capacity(cols);
        let mut row2 = Vec::with_capacity(cols);

        for _ in 0..cols {
            row1.push(rand::thread_rng().gen_range(0..100));
            row2.push(rand::thread_rng().gen_range(0..100));
        }

        matrix1.push(row1);
        matrix2.push(row2);
    }

    let result = add_matrices(&matrix1, &matrix2, rows, cols);

    println!("Matrix 1:");
    print_matrix(&matrix1);

    println!("Matrix 2:");
    print_matrix(&matrix2);

    println!("Result Matrix:");
    print_matrix(&result);
}

fn add_matrices(matrix1: &Vec<Vec<i32>>, matrix2: &Vec<Vec<i32>>, rows: usize, cols: usize) -> Vec<Vec<i32>> {
    let mut result = vec![vec![0; cols]; rows];

    for i in 0..rows {
        for j in 0..cols {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    result
}

fn print_matrix(matrix: &Vec<Vec<i32>>) {
    for row in matrix.iter() {
        for val in row.iter() {
            print!("{}\t", val);
        }
        println!();
    }
}
