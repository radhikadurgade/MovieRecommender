#include <stdio.h>
#include <string.h>

// Movie रचना (Structure)
typedef struct {
    char title[30];
    char genre[20];
} Movie;

int main() {
    // चित्रपटांचा डेटा (Dataset)
    Movie movies[10] = {
        {"3 Idiots", "Drama"},
        {"Dangal", "Sports"},
        {"Chhichhore", "Drama"},
        {"PK", "Comedy"},
        {"Taare Zameen Par", "Drama"},
        {"Avengers", "Action"},
        {"Spider-Man", "Action"},
        {"Iron Man", "Action"},
        {"Batman", "Action"},
        {"Interstellar", "Sci-Fi"}
    };

    int total_movies = 10;
    int choice;

    printf("=========================================\n");
    printf("   🎬 MOVIE RECOMMENDATION SYSTEM (C)   \n");
    printf("=========================================\n\n");

    printf("उपलब्ध चित्रपट:\n");
    for (int i = 0; i < total_movies; i++) {
        printf("%d. %s (%s)\n", i + 1, movies[i].title, movies[i].genre);
    }

    printf("\nतुला आवडणाऱ्या चित्रपटाचा क्रमांक निवडा (1-10): ");
    
    // इनपुट घेताना सुरक्षित पद्धत
    if (scanf("%d", &choice) != 1) {
        printf("\nचुकीचे इनपुट! कृपया फक्त नंबर टाका.\n");
        return 0;
    }

    if (choice < 1 || choice > total_movies) {
        printf("\nअवैध निवड! कृपया 1 ते 10 मधील क्रमांक निवडा.\n");
        return 0;
    }

    // निवडलेला चित्रपट आणि त्याचा जॉनर (Genre)
    char selected_title[30];
    char selected_genre[20];
    strcpy(selected_title, movies[choice - 1].title);
    strcpy(selected_genre, movies[choice - 1].genre);

    printf("\n-----------------------------------------\n");
    printf("तुम्ही निवडलेला चित्रपट: %s [%s]\n", selected_title, selected_genre);
    printf("-----------------------------------------\n");
    printf("\nतुझ्यासाठी सुचवलेले इतर चित्रपट (%s Genre):\n", selected_genre);

    int count = 0;
    for (int i = 0; i < total_movies; i++) {
        // समान Genre असणारे आणि निवडलेला सोडून इतर चित्रपट दाखवणे
        if (strcmp(movies[i].genre, selected_genre) == 0 && strcmp(movies[i].title, selected_title) != 0) {
            count++;
            printf("%d. %s\n", count, movies[i].title);
        }
    }

    if (count == 0) {
        printf("सध्या या कॅटेगरीत इतर चित्रपट उपलब्ध नाहीत.\n");
    }

    printf("\n=========================================\n");
    return 0;
}