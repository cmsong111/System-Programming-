use std::io;
use std::collections::BTreeMap;

fn main() {
    let mut num_students = String::new();
    println!("Enter the number of students: ");
    io::stdin().read_line(&mut num_students).expect("Failed to read input");
    let num_students: usize = num_students.trim().parse().expect("Invalid input");

    let mut student_map = BTreeMap::new();

    for _ in 0..num_students {
        let mut name = String::new();
        let mut midterm = String::new();
        let mut final_score = String::new();
        println!("Enter student name: ");
        io::stdin().read_line(&mut name).expect("Failed to read input");
        let name = name.trim().to_string();
        println!("Enter midterm score for {}: ", name);
        io::stdin().read_line(&mut midterm).expect("Failed to read input");
        let midterm: i32 = midterm.trim().parse().expect("Invalid input");
        println!("Enter final score for {}: ", name);
        io::stdin().read_line(&mut final_score).expect("Failed to read input");
        let final_score: i32 = final_score.trim().parse().expect("Invalid input");

        student_map.insert(name, (midterm, final_score));
    }

    println!("\nStudent Information:");
    for (name, (midterm, final_score)) in &student_map {
        println!("Name: {}, Midterm: {}, Final: {}", name, midterm, final_score);
    }
}
