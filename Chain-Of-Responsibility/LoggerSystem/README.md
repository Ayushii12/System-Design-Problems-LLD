# Logger System

## Requirements
- Support multiple logging levels such as DEBUG, INFO, WARN and ERROR
- Ability to log messages
  
## Entities
- **LogProcessor**: The main handler  
  - InforLogProcessor: Extends the main class and handles Info logs
  - ErrorLogProcessor: Extends the main class and handles Error logs
  - DebugLogProcessor: Extends the main class and handles Debug logs
