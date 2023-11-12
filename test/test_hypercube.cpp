#include <gtest/gtest.h>

#include "Hypercube.hpp"

// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
TEST(TestHypercube, Volume) {
  {
    EB::Hypercube<double, 3> hc{};
    EXPECT_DOUBLE_EQ(EB::hypercube_volume(hc), 0.0);
  }

  {
    EB::Hypercube<double, 3> hc{
        EB::Interval{0.0, 1.0},
        EB::Interval{0.0, 1.0},
        EB::Interval{0.0, 1.0},
    };
    EXPECT_DOUBLE_EQ(EB::hypercube_volume(hc), 1.0);
  }

  {
    EB::Hypercube<double, 3> hc;
    hc[0] = {-1.0, 1.0};
    hc[1] = {-2.0, 2.0};
    hc[2] = {-3.0, 3.0};
    EXPECT_DOUBLE_EQ(EB::hypercube_volume(hc), 2.0 * 4.0 * 6.0);
  }
}

// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
TEST(TestHypercube, ContainsPoint) {
  {
    EB::Hypercube<double, 3> hc{};
    Eigen::Vector<double, 3> point{1.0, 1.0, 1.0};

    EXPECT_FALSE(EB::hypercube_contains_point(hc, point));
  }

  {
    EB::Hypercube<double, 3> hc{};
    hc[0] = {-1.0, 1.0};
    hc[1] = {-2.0, 2.0};
    hc[2] = {-3.0, 3.0};

    {
      Eigen::Vector<double, 3> point{1.0, 1.0, 1.0};
      EXPECT_TRUE(EB::hypercube_contains_point(hc, point));
    }
    {
      Eigen::Vector<double, 3> point{-1.0, 2.0, -3.0};
      EXPECT_TRUE(EB::hypercube_contains_point(hc, point));
    }
    {
      Eigen::Vector<double, 3> point{-1.5, 1.0, 1.0};
      EXPECT_FALSE(EB::hypercube_contains_point(hc, point));
    }
  }
}

// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
TEST(TestHypercube, ContainsHypercube) {
  {
    EB::Hypercube<double, 3> hc1{};
    EB::Hypercube<double, 3> hc2{};

    EXPECT_TRUE(EB::hypercube_contains_hypercube(hc1, hc2));
  }

  {
    EB::Hypercube<double, 3> hc1{
        EB::Interval{-1.0, 1.0},
        EB::Interval{-2.0, 2.0},
        EB::Interval{-3.0, 3.0},
    };

    EB::Hypercube<double, 3> hc2{
        EB::Interval{0.0, 1.0},
        EB::Interval{-2.0, 0.0},
        EB::Interval{-1.5, 1.5},
    };

    EXPECT_TRUE(EB::hypercube_contains_hypercube(hc1, hc2));
    EXPECT_FALSE(EB::hypercube_contains_hypercube(hc2, hc1));
  }

  {
    EB::Hypercube<double, 3> hc1{
        EB::Interval{-1.0, 1.0},
        EB::Interval{-2.0, 2.0},
        EB::Interval{-3.0, 3.0},
    };

    EB::Hypercube<double, 3> hc2{
        EB::Interval{0.0, 1.0},
        EB::Interval{-2.0, 0.0},
        EB::Interval{-3.5, 1.5},
    };

    EXPECT_FALSE(EB::hypercube_contains_hypercube(hc1, hc2));
    EXPECT_FALSE(EB::hypercube_contains_hypercube(hc2, hc1));
  }
}

// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
TEST(TestHypercube, Overlap) {
  {
    EB::Hypercube<double, 3> hc1{};
    EB::Hypercube<double, 3> hc2{};

    EXPECT_TRUE(EB::hypercubes_overlap(hc1, hc2));
  }

  {
    EB::Hypercube<double, 3> hc1{
        EB::Interval{-1.0, 1.0},
        EB::Interval{-2.0, 2.0},
        EB::Interval{-3.0, 3.0},
    };

    EB::Hypercube<double, 3> hc2{
        EB::Interval{0.0, 1.0},
        EB::Interval{-2.0, 0.0},
        EB::Interval{-1.5, 1.5},
    };

    EXPECT_TRUE(EB::hypercubes_overlap(hc1, hc2));
    EXPECT_TRUE(EB::hypercubes_overlap(hc2, hc1));
  }

  {
    EB::Hypercube<double, 3> hc1{
        EB::Interval{-1.0, 1.0},
        EB::Interval{-2.0, 2.0},
        EB::Interval{-3.0, 3.0},
    };

    EB::Hypercube<double, 3> hc2{
        EB::Interval{0.0, 1.0},
        EB::Interval{-2.0, 0.0},
        EB::Interval{-3.5, 1.5},
    };

    EXPECT_TRUE(EB::hypercubes_overlap(hc1, hc2));
    EXPECT_TRUE(EB::hypercubes_overlap(hc2, hc1));
  }

  {
    EB::Hypercube<double, 3> hc1{
        EB::Interval{0.0, 1.0},
        EB::Interval{0.0, 2.0},
        EB::Interval{0.0, 3.0},
    };

    EB::Hypercube<double, 3> hc2{
        EB::Interval{-1.0, 0.0},
        EB::Interval{-2.0, 0.0},
        EB::Interval{-3.0, 0.0},
    };

    EXPECT_TRUE(EB::hypercubes_overlap(hc1, hc2));
    EXPECT_TRUE(EB::hypercubes_overlap(hc2, hc1));
  }

  {
    EB::Hypercube<double, 3> hc1{
        EB::Interval{0.1, 1.0},
        EB::Interval{0.1, 2.0},
        EB::Interval{0.1, 3.0},
    };

    EB::Hypercube<double, 3> hc2{
        EB::Interval{-1.0, -0.1},
        EB::Interval{-2.0, -0.1},
        EB::Interval{-3.0, -0.1},
    };

    EXPECT_FALSE(EB::hypercubes_overlap(hc1, hc2));
    EXPECT_FALSE(EB::hypercubes_overlap(hc2, hc1));
  }

  {
    EB::Hypercube<double, 2> hc1{
        EB::Interval{0.0, 1.0},
        EB::Interval{0.0, 1.0},
    };

    EB::Hypercube<double, 2> hc2{
        EB::Interval{0.0, 1.0},
        EB::Interval{2.0, 3.0},
    };

    EXPECT_FALSE(EB::hypercubes_overlap(hc1, hc2)) << "Hypercubes\n"
                                                   << hc1 << "\nand\n"
                                                   << hc2 << "\ndo not overlap.";
  }

  {
    EB::Hypercube<double, 2> hc1{
        EB::Interval{-1.0, 1.0},
        EB::Interval{-1.0, 1.0},
    };

    EB::Hypercube<double, 2> hc2{
        EB::Interval{-0.5, 0.5},
        EB::Interval{-0.5, 0.5},
    };

    EXPECT_TRUE(EB::hypercubes_overlap(hc1, hc2)) << "Hypercubes\n"
                                                  << hc1 << "\nand\n"
                                                  << hc2 << "\noverlap.";
  }
}

// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
TEST(TestHypercube, MergeTwoHypercubes) {
  {
    EB::Hypercube<double, 3> hc1{};
    EB::Hypercube<double, 3> hc2{};

    EB::internal::merge_two_hypercubes(hc1, hc2);
    EXPECT_EQ(hc1, hc2);
  }

  {
    EB::Hypercube<double, 3> hc1{
        EB::Interval{-1.0, 1.0},
        EB::Interval{-2.0, 2.0},
        EB::Interval{-3.0, 3.0},
    };

    EB::Hypercube<double, 3> hc2{
        EB::Interval{0.0, 1.0},
        EB::Interval{-2.0, 5.0},
        EB::Interval{-1.5, 11.5},
    };

    EB::Hypercube<double, 3> hc3 = hc1;

    EB::internal::merge_two_hypercubes(hc1, hc2);
    EXPECT_TRUE(EB::hypercube_contains_hypercube(hc1, hc2));
    EXPECT_TRUE(EB::hypercube_contains_hypercube(hc1, hc3));
  }
}

// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------
TEST(TestHypercube, MergeHypercubes) {
  {
    const std::vector<EB::Hypercube<double, 3>> single_hcs{};
    const std::vector<EB::Hypercube<double, 3>> merged_hcs = EB::merge_hypercubes(single_hcs);
    EXPECT_EQ(merged_hcs.size(), 0ul);
  }

  {
    const std::vector<EB::Hypercube<double, 3>> single_hcs{
        EB::Hypercube<double, 3>{},
        EB::Hypercube<double, 3>{},
        EB::Hypercube<double, 3>{},
        EB::Hypercube<double, 3>{},
    };

    const std::vector<EB::Hypercube<double, 3>> merged_hcs = EB::merge_hypercubes(single_hcs);

    ASSERT_EQ(merged_hcs.size(), 1ul);

    EB::Hypercube<double, 3> merge{};
    EXPECT_EQ(merged_hcs[0], merge);
  }

  {
    const std::vector<EB::Hypercube<double, 3>> single_hcs{
        EB::Hypercube<double, 3>{
            EB::Interval{-1.0, 0.0},
            EB::Interval{-2.0, 0.0},
            EB::Interval{-3.0, 0.0},
        },
        EB::Hypercube<double, 3>{
            EB::Interval{1.0, 2.0},
            EB::Interval{2.0, 4.0},
            EB::Interval{3.0, 6.0},
        },
        EB::Hypercube<double, 3>{
            EB::Interval{0.0, 1.0},
            EB::Interval{0.0, 2.0},
            EB::Interval{0.0, 3.0},
        },
        EB::Hypercube<double, 3>{
            EB::Interval{10.0, 11.0},
            EB::Interval{10.0, 11.0},
            EB::Interval{10.0, 11.0},
        },
    };

    const std::vector<EB::Hypercube<double, 3>> merged_hcs = EB::merge_hypercubes(single_hcs);

    ASSERT_EQ(merged_hcs.size(), 2ul);

    const EB::Hypercube<double, 3> first_merge{
        EB::Interval{-1.0, 2.0},
        EB::Interval{-2.0, 4.0},
        EB::Interval{-3.0, 6.0},
    };
    EXPECT_EQ(merged_hcs[0], first_merge);

    const EB::Hypercube<double, 3> second_merge{
        EB::Interval{10.0, 11.0},
        EB::Interval{10.0, 11.0},
        EB::Interval{10.0, 11.0},
    };
    EXPECT_EQ(merged_hcs[1], second_merge);
  }

  {
    const std::vector<EB::Hypercube<double, 3>> single_hcs{
        EB::Hypercube<double, 3>{
            EB::Interval{0.0, 1.0},
            EB::Interval{0.0, 1.0},
            EB::Interval{0.0, 1.0},
        },
        EB::Hypercube<double, 3>{
            EB::Interval{2.0, 3.0},
            EB::Interval{2.0, 3.0},
            EB::Interval{2.0, 3.0},
        },
        EB::Hypercube<double, 3>{
            EB::Interval{4.0, 5.0},
            EB::Interval{4.0, 5.0},
            EB::Interval{4.0, 5.0},
        },
        EB::Hypercube<double, 3>{
            EB::Interval{6.0, 7.0},
            EB::Interval{6.0, 7.0},
            EB::Interval{6.0, 7.0},
        },
    };

    const std::vector<EB::Hypercube<double, 3>> merged_hcs = EB::merge_hypercubes(single_hcs);

    EXPECT_EQ(merged_hcs, single_hcs);
  }

  {
    const std::vector<EB::Hypercube<double, 2>> single_hcs{
        EB::Hypercube<double, 2>{
            EB::Interval{1.0, 3.0},
            EB::Interval{1.0, 3.0},
        },
        EB::Hypercube<double, 2>{
            EB::Interval{2.0, 3.0},
            EB::Interval{4.0, 6.0},
        },
    };

    const std::vector<EB::Hypercube<double, 2>> merged_hcs = EB::merge_hypercubes(single_hcs);
    ASSERT_EQ(merged_hcs.size(), 2ul);
    EXPECT_EQ(single_hcs, merged_hcs);
  }

  {
    const std::vector<EB::Hypercube<double, 2>> single_hcs{
        EB::Hypercube<double, 2>{
            EB::Interval{1.0, 3.0},
            EB::Interval{1.0, 3.0},
        },
        EB::Hypercube<double, 2>{
            EB::Interval{2.0, 3.0},
            EB::Interval{4.0, 6.0},
        },
        EB::Hypercube<double, 2>{
            EB::Interval{2.0, 10.0},
            EB::Interval{2.0, 10.0},
        },
    };

    const std::vector<EB::Hypercube<double, 2>> merged_hcs = EB::merge_hypercubes(single_hcs);
    ASSERT_EQ(merged_hcs.size(), 1ul);

    const EB::Hypercube<double, 2> merge{
        EB::Interval{1.0, 10.0},
        EB::Interval{1.0, 10.0},
    };
    EXPECT_EQ(merged_hcs[0], merge);
  }

  {
    const std::vector<EB::Hypercube<double, 2>> single_hcs{
        EB::Hypercube<double, 2>{
            EB::Interval{2.0, 8.0},
            EB::Interval{2.0, 4.0},
        },
        EB::Hypercube<double, 2>{
            EB::Interval{2.0, 5.0},
            EB::Interval{6.0, 8.0},
        },
        EB::Hypercube<double, 2>{
            EB::Interval{6.0, 9.0},
            EB::Interval{1.0, 9.0},
        },
    };

    const std::vector<EB::Hypercube<double, 2>> merged_hcs = EB::merge_hypercubes(single_hcs);

    for (const auto& hc : merged_hcs) {
      std::cout << hc << '\n';
    }

    ASSERT_EQ(merged_hcs.size(), 1ul) << "All hypercubes should be merged into one.";

    const EB::Hypercube<double, 2> merge{
        EB::Interval{2.0, 9.0},
        EB::Interval{1.0, 9.0},
    };
    EXPECT_EQ(merged_hcs[0], merge);
  }
}
