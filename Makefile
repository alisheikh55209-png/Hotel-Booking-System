# ==============================================================================
# Hotel Booking/Reservation System - Makefile
# ==============================================================================
# Project: Hotel Booking/Reservation System
# Language: C++
# Version: 2.0 (Enhanced)
#
# Team Members:
# - M. Ali Sheikh (70151489) - Team Lead
# - Zaid (70149441)
# - Anas Abid (70150234)
# - Hussain Muavia (70147427)
#
# Date Created: 14-05-2024
# Last Updated: 31-12-2025
# ==============================================================================

# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -pedantic
LDFLAGS =

# Project Files
TARGET = HotelSystem
SOURCE = "Hotel Reservation or Booking System.cpp"
DATABASE = add.txt

# Colors for output (Unix-like systems)
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[1;33m
BLUE = \033[0;34m
NC = \033[0m # No Color

# ==============================================================================
# Main Targets
# ==============================================================================

.PHONY: all clean run help install uninstall

# Default target
all: $(TARGET)
	@echo "$(GREEN)✓ Build completed successfully!$(NC)"
	@echo "$(BLUE)Executable: $(TARGET).exe$(NC)"

# Compile the program
$(TARGET): $(SOURCE)
	@echo "$(YELLOW)Compiling $(SOURCE)...$(NC)"
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET) $(LDFLAGS)
	@echo "$(GREEN)✓ Compilation successful!$(NC)"

# Clean build artifacts
clean:
	@echo "$(YELLOW)Cleaning up build artifacts...$(NC)"
	rm -f $(TARGET).exe $(TARGET).o *.o *.out
	@echo "$(GREEN)✓ Clean completed!$(NC)"

# Clean everything including database
clean-all: clean
	@echo "$(YELLOW)Removing database file...$(NC)"
	rm -f $(DATABASE)
	@echo "$(GREEN)✓ Full cleanup completed!$(NC)"

# Run the program
run: $(TARGET)
	@echo "$(BLUE)Starting Hotel Booking System...$(NC)"
	./$(TARGET).exe

# Build and run
build-run: all run

# Install (copy executable to system)
install: $(TARGET)
	@echo "$(YELLOW)Installing $(TARGET)...$(NC)"
	cp $(TARGET).exe /usr/local/bin/$(TARGET) 2>/dev/null || \
	cp $(TARGET).exe ~/bin/$(TARGET) 2>/dev/null || \
	echo "$(RED)Installation failed. Please install manually.$(NC)"
	@echo "$(GREEN)✓ Installation completed!$(NC)"

# Uninstall
uninstall:
	@echo "$(YELLOW)Uninstalling $(TARGET)...$(NC)"
	rm -f /usr/local/bin/$(TARGET) ~/bin/$(TARGET)
	@echo "$(GREEN)✓ Uninstallation completed!$(NC)"

# Show help
help:
	@echo "$(BLUE)Hotel Booking System - Makefile Help$(NC)"
	@echo "======================================"
	@echo ""
	@echo "$(YELLOW)Available targets:$(NC)"
	@echo "  all         - Build the project (default)"
	@echo "  clean       - Remove build artifacts"
	@echo "  clean-all   - Remove build artifacts and database"
	@echo "  run         - Run the program"
	@echo "  build-run   - Build and run the program"
	@echo "  install     - Install executable to system"
	@echo "  uninstall   - Remove executable from system"
	@echo "  help        - Show this help message"
	@echo ""
	@echo "$(YELLOW)Usage examples:$(NC)"
	@echo "  make              # Build the project"
	@echo "  make run          # Build and run"
	@echo "  make clean        # Clean up"
	@echo "  make help         # Show help"

# ==============================================================================
# Development Targets
# ==============================================================================

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: all
	@echo "$(BLUE)Debug build completed!$(NC)"

# Release build (optimized)
release: CXXFLAGS += -O3 -DNDEBUG
release: all
	@echo "$(BLUE)Release build completed!$(NC)"

# Check syntax without compiling
syntax:
	$(CXX) -fsyntax-only $(CXXFLAGS) $(SOURCE)

# Show project info
info:
	@echo "$(BLUE)Hotel Booking System - Project Information$(NC)"
	@echo "=========================================="
	@echo "Source File: $(SOURCE)"
	@echo "Target:      $(TARGET).exe"
	@echo "Compiler:    $(CXX)"
	@echo "Flags:       $(CXXFLAGS)"
	@echo "Database:    $(DATABASE)"

# ==============================================================================
# Git Integration (for easy uploading)
# ==============================================================================

# Add all files to git
git-add:
	@echo "$(YELLOW)Adding files to git...$(NC)"
	git add .
	@echo "$(GREEN)✓ Files added to staging area!$(NC)"

# Commit changes
git-commit:
	@echo "$(YELLOW)Committing changes...$(NC)"
	git commit -m "Update: Enhanced Hotel Booking System v2.0"
	@echo "$(GREEN)✓ Changes committed!$(NC)"

# Push to GitHub
git-push:
	@echo "$(YELLOW)Pushing to GitHub...$(NC)"
	git push origin main
	@echo "$(GREEN)✓ Pushed to GitHub successfully!$(NC)"

# Full git workflow
git-upload: git-add git-commit git-push
	@echo "$(GREEN)✓ Project uploaded to GitHub!$(NC)"

# Check git status
git-status:
	@echo "$(BLUE)Git Status:$(NC)"
	git status --short

# ==============================================================================
# Utility Targets
# ==============================================================================

# Create backup
backup:
	@echo "$(YELLOW)Creating backup...$(NC)"
	tar -czf backup_$(shell date +%Y%m%d_%H%M%S).tar.gz * 2>/dev/null || \
	zip backup_$(shell date +%Y%m%d_%H%M%S).zip * 2>/dev/null || \
	echo "$(RED)Backup creation failed. Install tar or zip.$(NC)"
	@echo "$(GREEN)✓ Backup created!$(NC)"

# Show file sizes
size:
	@echo "$(BLUE)File Sizes:$(NC)"
	@ls -lh $(SOURCE) $(TARGET).exe 2>/dev/null || echo "Files not found"

# Count lines of code
count:
	@echo "$(BLUE)Lines of Code:$(NC)"
	@wc -l $(SOURCE) 2>/dev/null || echo "Source file not found"

# ==============================================================================
# Dependencies
# ==============================================================================

# Ensure database file exists
$(DATABASE):
	@echo "$(YELLOW)Creating database file...$(NC)"
	touch $(DATABASE)
	@echo "$(GREEN)✓ Database initialized!$(NC)"

# ==============================================================================
# End of Makefile
# ==============================================================================
