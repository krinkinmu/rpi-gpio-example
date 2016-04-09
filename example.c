#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/init.h>

#include <linux/platform_device.h>
#include <linux/gpio/consumer.h>
#include <linux/of.h>

static struct gpio_desc *gpio;

static int example_probe(struct platform_device *pdev)
{
	gpio = gpiod_get(&pdev->dev, "out", GPIOD_OUT_HIGH);

	if (IS_ERR(gpio)) {
		pr_err("failed to acquire GPIO\n");
		return PTR_ERR(gpio);
	}
	return 0;
}

static int example_remove(struct platform_device *pdev)
{
	gpiod_put(gpio);
	return 0;
}

static const struct of_device_id example_of_ids[] = {
	{ .compatible = "spbau,example" },
	{ }
};

static struct platform_driver example = {
	.probe = &example_probe,
	.remove = &example_remove,
	.driver = {
		.name = "example",
		.owner = THIS_MODULE,
		.of_match_table = example_of_ids,
	},
};

MODULE_DEVICE_TABLE(of, example_of_ids);
module_platform_driver(example);
MODULE_LICENSE("GPL");
