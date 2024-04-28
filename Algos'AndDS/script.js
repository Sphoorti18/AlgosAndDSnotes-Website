// JavaScript code for interacting with the HTML elements

// Function to perform some action when the document is fully loaded
document.addEventListener("DOMContentLoaded", function() {
    // Select the header element
    const header = document.querySelector("header");

    // Add a click event listener to the header element
    header.addEventListener("click", function() {
        // Alert a message when the header is clicked
        alert("You clicked the header!");
    });

    // Select the navigation links
    const navLinks = document.querySelectorAll("nav ul li a");

    // Loop through each navigation link and add a click event listener
    navLinks.forEach(function(navLink) {
        navLink.addEventListener("click", function(event) {
            // Prevent the default behavior of the link (e.g., navigating to a new page)
            event.preventDefault();

            // Get the href attribute of the clicked link
            const href = this.getAttribute("href");

            // Log the href attribute to the console
            console.log("Clicked link:", href);
        });
    });

    // Function to change the background color of the footer when the mouse hovers over it
    const footer = document.querySelector("footer");
    footer.addEventListener("mouseover", function() {
        this.style.backgroundColor = "#ffd1dc"; // Lighter pink
    });

    // Function to change the background color of the footer back to its original color when the mouse leaves it
    footer.addEventListener("mouseleave", function() {
        this.style.backgroundColor = "#ff80ab"; // Original pink
    });
});
