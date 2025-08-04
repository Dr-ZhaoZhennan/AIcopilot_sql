#!/bin/bash

echo "=========================================="
echo "    Copilot SQL 优化助手 - SQLCoder版本"
echo "=========================================="
echo ""

# 检查程序是否存在
if [ ! -f "./main" ]; then
    echo "正在编译程序..."
    make clean && make
    if [ $? -ne 0 ]; then
        echo "编译失败！请检查依赖是否安装。"
        echo "安装依赖：sudo apt-get install libcurl4-openssl-dev nlohmann-json3-dev"
        exit 1
    fi
fi

# 检查配置文件
if [ ! -f "./config/ai_models.json" ]; then
    echo "错误：找不到配置文件 config/ai_models.json"
    exit 1
fi

# 显示模型信息
echo "当前配置的AI模型："
echo "1. deepseek-chat (在线模型)"
echo "2. deepseek-reasoner (在线模型)"
echo "3. ollama-sqlcoder (本地模型，需要Ollama)"
echo ""

# 检查Ollama服务状态（可选）
if command -v ollama &> /dev/null; then
    echo "检测到Ollama已安装"
    if curl -s http://localhost:11434/api/tags > /dev/null 2>&1; then
        echo "✓ Ollama服务运行正常"
    else
        echo "⚠ Ollama服务未运行，如需使用sqlcoder模型请启动：ollama serve"
    fi
else
    echo "⚠ 未检测到Ollama，如需使用sqlcoder模型请安装："
    echo "   访问 https://ollama.ai 下载安装"
    echo "   然后运行：ollama pull sqlcoder"
fi

echo ""
echo "启动程序..."
echo "=========================================="

# 运行程序
./main 