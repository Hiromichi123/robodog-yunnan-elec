#pragma once

#include <string>
#include <nlohmann/json.hpp>
#include "layer0_common/goto_config.hpp"

namespace mission {

struct GotoSavedConfig {
    GotoConfig config{};
    std::string saved_at;
};

std::string goto_default_config_path();
nlohmann::json goto_config_json(const GotoConfig& config);
GotoSavedConfig parse_goto_saved(const std::string& text);
// Missing file is normal; any other failure throws without changing output.
bool load_goto_saved(const std::string& path, GotoSavedConfig& output);
// Throws on failure, including uncertain durability after rename.
GotoSavedConfig save_goto_config(const std::string& path, const GotoConfig& config);

}  // namespace mission
