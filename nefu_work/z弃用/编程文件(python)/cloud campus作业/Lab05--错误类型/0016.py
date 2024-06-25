def is_valid_score(score):
    try:
          
        if score < 0 or score > 100:
            raise ValueError("Invalid score!")  
        return True
    except (ValueError, TypeError):
        return "ERROR: Invalid score!"  
print(is_valid_score(85.5))
    