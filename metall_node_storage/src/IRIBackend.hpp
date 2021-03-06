#ifndef METALL_IRIBACKEND_HPP
#define METALL_IRIBACKEND_HPP

#include <metall/metall.hpp>

#include <rdf4cpp/rdf/storage/node/identifier/NodeID.hpp>
#include <rdf4cpp/rdf/storage/node/view/IRIBackendView.hpp>

#include <compare>
#include <memory>
#include <string>
#include <string_view>

namespace rdf4cpp::rdf::storage::node::metall_node_storage {


class IRIBackend {
    std::string iri;

public:
    explicit IRIBackend(std::string_view iri) noexcept;
    explicit IRIBackend(view::IRIBackendView view) noexcept;
    auto operator<=>(const IRIBackend &) const = default;
    auto operator<=>(view::IRIBackendView const &other) const noexcept {
        return view::IRIBackendView(*this) <=> other;
    }
    std::partial_ordering operator<=>(metall::offset_ptr<IRIBackend> const &other) const noexcept;

    [[nodiscard]] std::string_view identifier() const noexcept;

    explicit operator view::IRIBackendView() const noexcept;
};
std::partial_ordering operator<=>(metall::offset_ptr<IRIBackend> const &self, metall::offset_ptr<IRIBackend> const &other) noexcept;
}  // namespace rdf4cpp::rdf::storage::node::metall_node_storage
namespace rdf4cpp::rdf::storage::node::view {
inline std::partial_ordering operator<=>(IRIBackendView const &lhs, metall::offset_ptr<metall_node_storage::IRIBackend> const &rhs) noexcept {
    return lhs <=> IRIBackendView(*rhs);
}
}  // namespace rdf4cpp::rdf::storage::node::view
#endif  //METALL_IRIBACKEND_HPP
