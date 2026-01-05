# Pharmacy Drug Tracking System (Eczane İlaç Takip Sistemi)

A simple C-based console application for tracking pharmacy inventory. This system allows you to add new drugs, generate barcodes automatically, and list current stock levels. All data is persisted in a text file (`ilaclar.txt`).

## Features

- **Add New Drug:** Enter drug details (Name, Expiry Date, Stock, Cold Chain, Prescription status, Price).
- **Automatic Barcode:** Generates a random 12-digit barcode for each new entry.
- **Stock Listing:** View all registered drugs in a formatted table.
- **Data Persistence:** Automatically saves and loads data from `ilaclar.txt`.
- **Input Validation:** Prevents invalid inputs and buffer overflows.

## How to Compile and Run

You need a C compiler (like `gcc`) to build this project.

1.  **Open a terminal** in the project directory.
2.  **Compile** the code:
    ```bash
    gcc eczaneilactakipsistemi.c -o eczane
    ```
3.  **Run** the executable:
    - On Windows:
      ```powershell
      .\eczane.exe
      ```
    - On macOS/Linux:
      ```bash
      ./eczane
      ```

## Usage

1.  **Main Menu:**

    - Select `1` to list stocks.
    - Select `2` to add a new drug.
    - Select `3` to exit.

2.  **Adding a Drug:**
    - Follow the prompts to enter drug information.
    - Note: Drug names should be entered without spaces (or use underscores).

## File Structure

- `eczaneilactakipsistemi.c`: Main source code.
- `ilaclar.txt`: Database file (created automatically).
- `README.md`: This documentation file.
