#include <fstream>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>

namespace fs = std::filesystem;

// Enum conversion rules MUST be inside the same namespace. See
// https://nlohmann.github.io/json/api/macros/nlohmann_json_serialize_enum/#notes
// prerequisites.
namespace spdlog::level {
NLOHMANN_JSON_SERIALIZE_ENUM(level_enum, {
                                             {trace, "trace"},
                                             {debug, "debug"},
                                             {info, "info"},
                                             {warn, "warn"},
                                             {err, "err"},
                                             {critical, "critical"},
                                             {off, "off"},
                                         });
} // namespace spdlog::level

struct Config {
  public:
    spdlog::level::level_enum log_level{spdlog::level::info};

    NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Config, log_level);

    Config() = default;
    Config(nlohmann::json const &json)
    {
        json.get_to(*this);
    }
    explicit Config(fs::path const &config_path)
        : Config([&]() {
              std::ifstream file(config_path);
              if (!fs::exists(config_path)) {
                  throw std::runtime_error("failed to open config file " +
                                           config_path.string() +
                                           ": file doesn't exist");
              }
              if (!file.is_open()) {
                  throw std::runtime_error(
                      "failed to open config file: " + config_path.string() +
                      ": unknown error");
              }
              try {
                  return nlohmann::json::parse(file);
              }
              catch (nlohmann::json::exception const &e) {
                  throw std::runtime_error("invalid JSON in " +
                                           std::string(config_path.string()) +
                                           ": " + e.what());
              }
          }())
    {
    }
};
