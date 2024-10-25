<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html lang="zh">
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>级联选择器</title>
</head>
<body>
    <h1>省市级联选择器</h1>
    <label for="province">选择省份:</label>
    <select id="province">
        <option value="">--请选择--</option>
        <option value="黑龙江">黑龙江</option>
        <option value="吉林">吉林</option>
        <option value="辽宁">辽宁</option>
    </select>

    <label for="city">选择城市:</label>
    <select id="city" disabled>
        <option value="">--请选择--</option>
    </select>

    <script>
        const cities = {
            "黑龙江": ["哈尔滨", "齐齐哈尔", "佳木斯", "牡丹江"],
            "吉林": ["长春", "吉林市", "四平", "辽源"],
            "辽宁": ["沈阳", "大连", "鞍山", "抚顺"]
        };

        const provinceSelect = document.getElementById('province');
        const citySelect = document.getElementById('city');

        provinceSelect.addEventListener('change', function() {
            const selectedProvince = this.value;
            citySelect.innerHTML = '<option value="">--请选择--</option>'; // 清空城市选择框

            if (selectedProvince) {
                const cityOptions = cities[selectedProvince];
                cityOptions.forEach(city => {
                    const option = document.createElement('option');
                    option.value = city;
                    option.textContent = city;
                    citySelect.appendChild(option);
                });
                citySelect.disabled = false; // 启用城市选择框
            } else {
                citySelect.disabled = true; // 禁用城市选择框
            }
        });
    </script>
</body>
</html>
