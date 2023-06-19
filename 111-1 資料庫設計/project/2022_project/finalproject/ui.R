# Load the ggplot2 package which provides
# the 'mpg' dataset.

fluidPage(
  titlePanel("名畫搜尋器"),
  # Create a new Row in the UI for selectInputs
  
  fluidRow(
    column(4,
           selectInput("time",
                       "時代/主義:",
                       c("All",
                         unique(as.character(painting$time))))
    ),
    column(4,
           selectInput("name",
                       "畫作名稱:",
                       c("All",
                         unique(as.character(painting$name))))
    ),

    column(4,
           selectInput("painter",
                       "畫家:",
                       c("All",
                         unique(as.character(painting$painter))))
    ),
    column(4,
           selectInput("pigment",
                       "原作材質:",
                       c("All",
                         unique(as.character(painting$pigment))))
    ),
    column(4,
           selectInput("attribute",
                       "屬性:",
                       c("All",
                         unique(as.character(painting$attribute))))
    ),
    column(4,
           selectInput("tag",
                       "標籤:",
                       c("All",
                         unique(as.character(tag$tag))))
    )
  ),
  # Create a new row for the table.
  DT::dataTableOutput("table")
)
