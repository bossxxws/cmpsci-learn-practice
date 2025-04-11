package com.highcom.config;

import com.google.code.kaptcha.impl.DefaultKaptcha;
import com.google.code.kaptcha.util.Config;
import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Component;

import java.util.Properties;

//Google提供的一个图形验证码插件
@Component
public class KaptchaConfig {

	
	@Bean(name = "captchaProducer")
	public DefaultKaptcha getDefaultKaptcha(){
		DefaultKaptcha defaultKaptcha = new DefaultKaptcha();
		Properties properties = new Properties();
		properties.setProperty("kaptcha.border", "no");
		properties.setProperty("kaptcha.border.color", "white");
		properties.setProperty("kaptcha.textproducer.font.color", "black");
		properties.setProperty("kaptcha.image.width", "110");
		properties.setProperty("kaptcha.image.height", "46");
		properties.setProperty("kaptcha.textproducer.char.string","23456789abcdefghkmnpqrstuvwxyzABCDEFGHKMNPRSTUVWXYZ");
		properties.setProperty("kaptcha.textproducer.font.size", "45");
		properties.setProperty("kaptcha.textproducer.char.space","2");
		properties.setProperty("kaptcha.session.key", "code");
		properties.setProperty("kaptcha.textproducer.char.length", "4");
		properties.setProperty("kaptcha.background.clear.from", "white");
		properties.setProperty("kaptcha.textproducer.font.names", "宋体,楷体,微软雅黑");
		// 这里 是去掉 噪点颜色
		properties.setProperty("kaptcha.noise.color", "black");
		// 这是 是图片样式配置 原生的有三种 水纹 、 鱼眼 、 阴影
		// 这里是 我们自己实现的一个 也就是 样式自定义
		//properties.setProperty("kaptcha.obscurificator.impl","com.highcom.utils.NoWaterRipple");
		// 配置使用原生的 无噪 实现类 NoNoise
		properties.setProperty("kaptcha.noise.impl","com.google.code.kaptcha.impl.DefaultNoise");
		Config config = new Config(properties);
		defaultKaptcha.setConfig(config);

		return defaultKaptcha;
	}
}
