#pragma once

#include <functional>

namespace collections
{
    class Item;
    class object_base;
    class tes_context;

    namespace path_resolving {

        void resolve(tes_context& ctx, Item& item, const char *cpath, std::function<void(Item *)> itemFunction, bool createMissingKeys = false);

        void resolve(tes_context& ctx, object_base *collection, const char *cpath, std::function<void(Item *)> itemFunction, bool createMissingKeys = false);

        template<class T>
        inline T _resolve(tes_context& ctx, object_base *collection, const char *cpath, T def = T(0)) {
            resolve(ctx, collection, cpath, [&](Item *itm) {
                if (itm) {
                    def = itm->readAs<T>();
                }
            });

            return def;
        }
    }
}