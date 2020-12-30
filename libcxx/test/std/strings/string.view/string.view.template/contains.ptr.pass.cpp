//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// UNSUPPORTED: c++03, c++11, c++14, c++17, c++20

// <string_view>

//   constexpr bool contains(const CharT *x) const;

#include <string_view>
#include <cassert>

#include "test_macros.h"
#include "constexpr_char_traits.h"

int main(int, char**)
{
    {
    using SV = std::string_view;
    const char *s = "abcde";
    SV  sv0 {};
    SV  sv1 { s + 4, 1 };
//  SV  sv2 { s + 3, 2 };
    SV  sv3 { s + 2, 3 };
//  SV  sv4 { s + 1, 4 };
//  SV  sv5 { s    , 5 };
    SV  svNot {"xyz", 3 };

    LIBCPP_ASSERT_NOEXCEPT(sv0.contains(""));

    assert ( sv0.contains(""));
    assert (!sv0.contains("e"));

    assert ( sv1.contains(""));
    assert (!sv1.contains("d"));
    assert ( sv1.contains("e"));
    assert (!sv1.contains("de"));
    assert (!sv1.contains("cd"));
    assert (!sv1.contains("cde"));
    assert (!sv1.contains("bcde"));
    assert (!sv1.contains("abcde"));
    assert (!sv1.contains("xyz"));

    assert ( sv3.contains(""));
    assert ( sv3.contains("d"));
    assert ( sv3.contains("e"));
    assert ( sv3.contains("de"));
    assert ( sv3.contains("cd"));
    assert (!sv3.contains("cde"));
    assert (!sv3.contains("bcde"));
    assert (!sv3.contains("abcde"));
    assert (!sv3.contains("xyz"));

    assert ( svNot.contains(""));
    assert (!svNot.contains("d"));
    assert (!svNot.contains("e"));
    assert (!svNot.contains("de"));
    assert (!svNot.contains("cd"));
    assert (!svNot.contains("cde"));
    assert (!svNot.contains("bcde"));
    assert (!svNot.contains("abcde"));
    assert ( svNot.contains("xyz"));
    }

#if TEST_STD_VER > 11
    {
    using SV = std::basic_string_view<char, constexpr_char_traits<char>>;
    constexpr const char *s = "abcde";
    constexpr SV  sv0 {};
    constexpr SV  sv1 { s + 4, 1 };
//  constexpr SV  sv2 { s + 3, 2 };
    constexpr SV  sv3 { s + 2, 3 };
//  constexpr SV  sv4 { s + 1, 4 };
//  constexpr SV  sv5 { s,     5 };
    constexpr SV  svNot {"xyz", 3 };

    static_assert ( sv0.contains(""));
    static_assert (!sv0.contains("e"));

    static_assert ( sv1.contains(""));
    static_assert (!sv1.contains("d"));
    static_assert ( sv1.contains("e"));
    static_assert (!sv1.contains("de"));
    static_assert (!sv1.contains("cde"));
    static_assert (!sv1.contains("bcde"));
    static_assert (!sv1.contains("abcde"));
    static_assert (!sv1.contains("xyz"));

    static_assert ( sv3.contains(""));
    static_assert ( sv3.contains("d"));
    static_assert ( sv3.contains("e"));
    static_assert ( sv3.contains("de"));
    static_assert ( sv3.contains("cd"));
    static_assert ( sv3.contains("cde"));
    static_assert (!sv3.contains("bcde"));
    static_assert (!sv3.contains("abcde"));
    static_assert (!sv3.contains("xyz"));

    static_assert ( svNot.contains(""));
    static_assert (!svNot.contains("d"));
    static_assert (!svNot.contains("e"));
    static_assert (!svNot.contains("de"));
    static_assert (!svNot.contains("cd"));
    static_assert (!svNot.contains("cde"));
    static_assert (!svNot.contains("bcde"));
    static_assert (!svNot.contains("abcde"));
    static_assert ( svNot.contains("xyz"));
    }
#endif

  return 0;
}
