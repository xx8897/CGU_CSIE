# Load the ggplot2 package which provides
# the 'mpg' dataset.
library(ggplot2)

function(input, output) {
  # Filter data based on selections
  output$table <- DT::renderDataTable(DT::datatable({
    data <- painting
    if (input$name != "All") {
      data <- data[data$name == input$name,]
    }
    if (input$time != "All") {
      data <- data[data$time == input$time,]
    }
    if (input$painter != "All") {
      data <- data[data$painter == input$painter,]
    }
    if (input$attribute != "All") {
      data <- data[data$attribute == input$attribute,]
    }
    if (input$pigment != "All") {
      data <- data[data$pigment == input$pigment,]
    }
    if (input$tag != "All") {
      data <- data[data$tag == input$tag,]
    }
    data
  }))
  
}

