<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html lang="zh">
<head>
    <meta charset="UTF-8">
    <title>工资录入</title>
    <script>
        function calculateNetSalary() {
            // Get values from input fields
            const baseSalary = parseFloat(document.getElementById("baseSalary").value) || 0;
            const salaryLevel = parseFloat(document.getElementById("salaryLevel").value) || 0;
            const allowances = parseFloat(document.getElementById("allowances").value) || 0;
            const housingAllowance = parseFloat(document.getElementById("housingAllowance").value) || 0;
            const providentFund = parseFloat(document.getElementById("providentFund").value) || 0;
            const lunchFee = parseFloat(document.getElementById("lunchFee").value) || 0;
            const medicalInsurance = parseFloat(document.getElementById("medicalInsurance").value) || 0;
            const pensionInsurance = parseFloat(document.getElementById("pensionInsurance").value) || 0;
            const providentFundDeduction = parseFloat(document.getElementById("providentFundDeduction").value) || 0;
            const taxDeduction = parseFloat(document.getElementById("taxDeduction").value) || 0;

            // Calculate gross salary
            const grossSalary = baseSalary + salaryLevel + allowances + housingAllowance + providentFund + lunchFee;

            // Calculate net salary
            const netSalary = grossSalary - (medicalInsurance + pensionInsurance + providentFundDeduction + taxDeduction);

            // Display the result
            document.getElementById("result").innerText = "实发工资: " + netSalary.toFixed(2) + " 元";
        }
    </script>
    <style>
        body { font-family: Arial, sans-serif; }
        table { margin: 20px auto; }
        td { padding: 10px; }
        input[type="number"] { width: 100px; }
    </style>
</head>
<body>
    <h1 align="center">工资录入</h1>
    <table border="1">
        <tr>
            <td>岗位工资：</td>
            <td><input type="number" id="baseSalary" /></td>
        </tr>
        <tr>
            <td>薪级工资：</td>
            <td><input type="number" id="salaryLevel" /></td>
        </tr>
        <tr>
            <td>工作津贴：</td>
            <td><input type="number" id="allowances" /></td>
        </tr>
        <tr>
            <td>房补：</td>
            <td><input type="number" id="housingAllowance" /></td>
        </tr>
        <tr>
            <td>公积金补贴：</td>
            <td><input type="number" id="providentFund" /></td>
        </tr>
        <tr>
            <td>午餐费：</td>
            <td><input type="number" id="lunchFee" /></td>
        </tr>
        <tr>
            <td>医疗保险扣款：</td>
            <td><input type="number" id="medicalInsurance" /></td>
        </tr>
        <tr>
            <td>养老保险扣款：</td>
            <td><input type="number" id="pensionInsurance" /></td>
        </tr>
        <tr>
            <td>公积金扣款：</td>
            <td><input type="number" id="providentFundDeduction" /></td>
        </tr>
        <tr>
            <td>税务扣款：</td>
            <td><input type="number" id="taxDeduction" /></td>
        </tr>
        <tr>
            <td colspan="2" align="center">
                <button onclick="calculateNetSalary()">计算实发工资</button>
            </td>
        </tr>
    </table>
    <h2 id="result" align="center"></h2>
</body>
</html>
