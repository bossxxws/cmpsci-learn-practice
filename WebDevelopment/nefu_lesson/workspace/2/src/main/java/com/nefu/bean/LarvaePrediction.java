package com.nefu.bean;

public class LarvaePrediction {
    // 方法用于预测发生量
    public double predict(double precipitation, double humidity, double maxTempJan, double minTempJan, double minTempAug, double avgTempJul) {
        return 0.014 * precipitation +
               0.168 * humidity -
               0.159 * maxTempJan -
               0.145 * minTempJan -
               0.271 * minTempAug -
               0.899 * avgTempJul +
               4.544;
    }
}

