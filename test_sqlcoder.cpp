#include <iostream>
#include <vector>
#include <ai_engine.h>

int main() {
    std::cout << "=== SQLCoder配置测试程序 ===" << std::endl;
    
    // 测试加载AI配置
    std::vector<AIModelConfig> models;
    if (!load_ai_config("config/ai_models.json", models)) {
        std::cerr << "错误：无法加载AI配置文件" << std::endl;
        return 1;
    }
    
    std::cout << "成功加载 " << models.size() << " 个AI模型：" << std::endl;
    for (const auto& model : models) {
        std::cout << "  - " << model.name << " (" << model.type << ")" << std::endl;
        std::cout << "    URL: " << model.url << std::endl;
        std::cout << "    模型ID: " << model.model_id << std::endl;
        std::cout << "    API密钥: " << (model.api_key.empty() ? "无" : "已设置") << std::endl;
        std::cout << std::endl;
    }
    
    // 检查sqlcoder模型
    bool found_sqlcoder = false;
    for (const auto& model : models) {
        if (model.model_id == "sqlcoder") {
            found_sqlcoder = true;
            std::cout << "✓ 找到sqlcoder模型配置：" << std::endl;
            std::cout << "  - 名称: " << model.name << std::endl;
            std::cout << "  - 类型: " << model.type << std::endl;
            std::cout << "  - 端口: 11434 (Ollama默认端口)" << std::endl;
            break;
        }
    }
    
    if (!found_sqlcoder) {
        std::cout << "✗ 未找到sqlcoder模型配置" << std::endl;
    }
    
    // 检查在线模型
    int online_models = 0;
    for (const auto& model : models) {
        if (model.type == "openai") {
            online_models++;
        }
    }
    
    std::cout << "✓ 找到 " << online_models << " 个在线模型" << std::endl;
    
    std::cout << "\n配置测试完成！" << std::endl;
    std::cout << "\n使用建议：" << std::endl;
    std::cout << "1. 首次使用：选择在线模型（无需安装）" << std::endl;
    std::cout << "2. 专业优化：选择sqlcoder模型（需要Ollama）" << std::endl;
    std::cout << "3. 安装Ollama：访问 https://ollama.ai" << std::endl;
    std::cout << "4. 拉取sqlcoder：ollama pull sqlcoder" << std::endl;
    
    return 0;
} 