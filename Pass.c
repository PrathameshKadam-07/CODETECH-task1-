#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if the password contains at least one lowercase letter1
bool has_lower(const char *password) {
    while (*password) {
        if (islower(*password)) return true;
        password++;
    }
    return false;
}

// Function to check if the password contains at least one uppercase letter
bool has_upper(const char *password) {
    while (*password) {
        if (isupper(*password)) return true;
        password++;
    }
    return false;
}

// Function to check if the password contains at least one digit
bool has_digit(const char *password) {
    while (*password) {
        if (isdigit(*password)) return true;
        password++;
    }
    return false;
}

// Function to check if the password contains at least one special character
bool has_special(const char *password) {
    const char *special_characters = "@$!%*?&#";
    while (*password) {
        if (strchr(special_characters, *password)) return true;
        password++;
    }
    return false;
}

// Function to check if the password is a common password
bool is_common_password(const char *password) {
    const char *common_passwords[] = {
        "123456", "password", "12345678", "qwerty", "123456789",
        "12345", "1234", "111111", "1234567", "dragon"
    };
    for (int i = 0; i < 10; i++) {
        if (strcmp(password, common_passwords[i]) == 0) return true;
    }
    return false;
}

// Function to evaluate password strength
void evaluate_password_strength(const char *password) {
    int strength_score = 0;
    int length_criteria = strlen(password) >= 12;
    int complexity_criteria = has_lower(password) && has_upper(password) && has_digit(password) && has_special(password);
    int unique_criteria = !is_common_password(password);

    if (length_criteria) strength_score++;
    if (complexity_criteria) strength_score++;
    if (unique_criteria) strength_score++;

    printf("Password strength: ");
    if (strength_score == 3) {
        printf("STRONG\n");
    } else if (strength_score == 2) {
        printf("MODERATE\n");
    } else {
        printf("WEAK\n");
    }

    printf("Feedback:\n");
    if (!length_criteria) printf(" - Password should be at least 12 characters long.\n");
    if (!complexity_criteria) printf(" - Password should include a mix of uppercase letters, lowercase letters, numbers, and special characters.\n");
    if (!unique_criteria) printf(" - Password should be unique and not a common password.\n");
}

int main() {
    char password[256];
    printf("Enter your password: ");
    scanf("%s", password);

    evaluate_password_strength(password);

    return 0;
}
