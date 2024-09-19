#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Event {
    int day;
    int month;
    int year;
    char description[100];
};
void displayMenu() {
    printf("\nCalendar Application\n");
    printf("1. View events\n");
    printf("2. Add an event\n");
    printf("3. Delete an event\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}
void viewEvents(struct Event events[], int count, int day, int month, int year) {
    printf("\nEvents on %d/%d/%d:\n", day, month, year);
    for (int i = 0; i < count; ++i) {
        if (events[i].day == day && events[i].month == month && events[i].year == year) {
            printf("%s\n", events[i].description);
        }
    }
}
void addEvent(struct Event events[], int *count) {
    struct Event newEvent;
    printf("Enter event date (dd mm yyyy): ");
    scanf("%d %d %d", &newEvent.day, &newEvent.month, &newEvent.year);
    printf("Enter event description: ");
    getchar(); 
    fgets(newEvent.description, sizeof(newEvent.description), stdin);

    if (*count < 100) {
        events[*count] = newEvent;
        (*count)++;
        printf("Event added successfully!\n");
    } else {
        printf("Event limit reached. Cannot add more events.\n");
    }
}
void deleteEvent(struct Event events[], int *count) {
    int index;
    printf("Enter the index of the event to delete: ");
    scanf("%d", &index);

    if (index >= 0 && index < *count) {
        for (int i = index; i < *count - 1; ++i) {
            events[i] = events[i + 1];
        }
        (*count)--;
        printf("Event deleted successfully!\n");
    } else {
        printf("Invalid index. No event deleted.\n");
    }
}

int main() {
    struct Event events[100]; 
    int eventCount = 0;
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int day, month, year;
                    printf("Enter date to view events (dd mm yyyy): ");
                    scanf("%d %d %d", &day, &month, &year);
                    viewEvents(events, eventCount, day, month, year);
                }
                break;
            case 2:
                addEvent(events, &eventCount);
                break;
            case 3:
                deleteEvent(events, &eventCount);
                break;
            case 4:
                printf("Exiting the calendar application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
