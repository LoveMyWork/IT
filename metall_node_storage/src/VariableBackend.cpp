#include "VariableBackend.hpp"

namespace rdf4cpp::rdf::storage::node::metall_node_storage {

VariableBackend::VariableBackend(std::string_view name, bool anonymous) noexcept
    : name_(name), anonymous_(anonymous) {}
VariableBackend::VariableBackend(view::VariableBackendView view) noexcept : name_(view.name), anonymous_(view.is_anonymous) {}
std::partial_ordering VariableBackend::operator<=>(metall::offset_ptr<VariableBackend> const &other) const noexcept {
    if (other != nullptr)
        return *this <=> *other;
    else
        return std::partial_ordering::greater;
}
bool VariableBackend::is_anonymous() const noexcept {
    return anonymous_;
}
std::string_view VariableBackend::name() const noexcept {
    return name_;
}
VariableBackend::operator view::VariableBackendView() const noexcept {
    return {.name = name(),
            .is_anonymous = is_anonymous()};
}
std::partial_ordering operator<=>(const metall::offset_ptr<VariableBackend> &self, const metall::offset_ptr<VariableBackend> &other) noexcept {
    return *self <=> *other;
}
}  // namespace rdf4cpp::rdf::storage::node::metall_node_storage