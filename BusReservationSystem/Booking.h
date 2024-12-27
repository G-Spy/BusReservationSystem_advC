#ifndef BOOKING_H
#define BOOKING_H

struct Booking {
    int userId;         // Id of the user 
    int busNumber;      // Bus number to link to a Bus
    int bookedSeats;    // Number of seats booked
};

extern struct Booking bookings[500];   // Array to store bookings
extern int bookingCount;           // Counter for the number of bookings

#endif
