def get_odds_list(numbers):
    #返回列表中包含所有奇数
    if len(numbers)==0:
        return []
    else:
        if numbers[0]%2!=0:
            return [numbers[0]]+get_odds_list(numbers[1:])
        else:
            return get_odds_list(numbers[1:])