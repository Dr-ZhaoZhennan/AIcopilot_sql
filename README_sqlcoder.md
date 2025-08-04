# Copilot SQL 优化助手 - SQLCoder版本

一个基于AI的GaussDB SQL优化工具，支持本地Ollama sqlcoder模型和在线API。

## 功能特性

- 🔍 **智能SQL分析**：自动分析SQL语句和执行计划
- 🤖 **AI驱动优化**：基于大模型生成优化建议
- 📊 **专业诊断**：详细解读执行计划中的关键节点
- 💡 **优化建议**：提供SQL重写、索引建议、参数调优等
- 🔄 **多轮交互**：支持补充信息和持续优化
- 🏠 **本地部署**：支持Ollama sqlcoder本地模型

## 支持的AI模型

### 本地模型（Ollama）
- **sqlcoder**：专门用于SQL生成和优化的模型，基于Code Llama架构

### 在线模型
- **deepseek-chat**：DeepSeek聊天模型
- **deepseek-reasoner**：DeepSeek推理模型

## 快速开始

### 1. 编译项目

```bash
make clean && make
```

### 2. 运行程序

```bash
./main
```

### 3. 选择AI模型

程序会显示可用的AI模型列表：
- **在线模型**：无需本地安装，直接使用
- **sqlcoder模型**：需要本地Ollama服务，专门针对SQL优化

## SQLCoder模型安装指南

### Windows用户

1. **下载Ollama**
   - 访问 https://ollama.com/download
   - 下载Windows版本并安装

2. **拉取sqlcoder模型**
   ```bash
   ollama pull sqlcoder
   ```

3. **启动Ollama服务**
   ```bash
   ollama serve
   ```

### Linux用户

1. **安装Ollama**
   ```bash
   curl -fsSL https://ollama.ai/install.sh | sh
   ```

2. **拉取sqlcoder模型**
   ```bash
   ollama pull sqlcoder
   ```

3. **启动Ollama服务**
   ```bash
   ollama serve
   ```

## 使用方法

### 1. 运行程序
```bash
./main
```

### 2. 选择AI模型
- 选择1-2：在线模型（推荐首次使用）
- 选择3：sqlcoder本地模型（需要Ollama服务）

### 3. 输入SQL和执行计划
- 输入SQL语句（多行支持）
- 输入EXPLAIN ANALYZE结果

### 4. 获取优化建议
程序会自动分析并提供：
- 执行计划解读
- 性能问题分析
- 优化建议
- 优化后的SQL

## 模型特点对比

| 特性 | 在线模型 | SQLCoder |
|------|----------|----------|
| 安装难度 | 无需安装 | 需要Ollama |
| 数据隐私 | 数据上传 | 本地处理 |
| 响应速度 | 依赖网络 | 本地快速 |
| SQL专业性 | 通用AI | 专门优化 |
| 网络依赖 | 必需 | 可选 |

## 故障排除

### 1. 编译错误
```bash
# 安装依赖
sudo apt-get install libcurl4-openssl-dev nlohmann-json3-dev
make clean && make
```

### 2. Ollama连接失败
```bash
# 检查服务状态
curl http://localhost:11434/api/tags

# 重启Ollama
ollama serve
```

### 3. sqlcoder模型问题
```bash
# 重新拉取模型
ollama pull sqlcoder

# 查看本地模型
ollama list
```

## 配置说明

### 修改默认模型
编辑 `config/ai_models.json`：
```json
{
  "default_model": "ollama-sqlcoder"
}
```

### 添加新的在线模型
```json
{
  "name": "your-model",
  "url": "https://api.example.com/chat",
  "api_key": "your-api-key",
  "model_id": "model-name",
  "type": "openai"
}
```

## 使用建议

- **首次使用**：选择在线模型，无需额外配置
- **数据敏感**：选择sqlcoder本地模型
- **专业优化**：sqlcoder对SQL优化更专业
- **网络受限**：选择本地模型

## 许可证

本项目采用MIT许可证。 