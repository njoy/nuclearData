#define CATCH_CONFIG_RUNNER

#include <ctime>
#include <algorithm>

#include "catch.hpp"

#include "nuclearData/API/Forms.hpp"

int testNumber = 0;

int main( int argc, const char* argv[] ){
  LOG(INFO) << "";
  LOG(INFO) << "Forms Tests";
  LOG(INFO) << "=========================================";
  int result = Catch::Session().run( argc, argv );
  LOG(INFO) << "Forms Tests Complete";
  return result;
}

SCENARIO("Forms ctors function correctly"){
  GIVEN("a set of vector forms"){
    std::set< nuclearData::API::Form< std::vector<int> > >
      sfv;
    std::vector<int> v = {1,2,3};
    auto upv = std::make_unique< std::vector<int> >(std::move(v));
    std::vector<int>& vr1 = *upv;
    std::string label("first");
    auto stamp = time(nullptr);
    auto tsr1 = stamp;
    sfv.insert( nuclearData::API::Form< std::vector<int> >(std::move(upv),
                                                           std::move(label),
                                                           stamp,
                                                           nullptr));
    v = {4,5,6};
    upv = std::make_unique< std::vector<int> >(std::move(v));
    std::vector<int>& vr2 = *upv;
    label = "second";
    stamp = time(nullptr);
    auto tsr2 = stamp;
    sfv.insert( nuclearData::API::Form< std::vector<int> >(std::move(upv),
                                                           std::move(label),
                                                           stamp,
                                                           nullptr));
    WHEN("passed to the Forms ctor"){
      THEN("no exception will be thrown and labels will appropaite"){
        LOG(INFO) << "Test " <<
          ++testNumber << ": [ctor] No Errors Expected";
        nuclearData::API::Forms< std::vector<int> > fs(std::move(sfv));
        const auto& fscr = fs;

        LOG(INFO) << "Test " <<
          ++testNumber << ": [ctor] No Errors Expected";
        nuclearData::API::Forms< std::vector<int> > blank;

        
        LOG(INFO) << "Test " <<
          ++testNumber << ": [labels] No Errors Expected";
        auto ls = fs.labels();
        REQUIRE(2 == ls.size());
        std::unordered_set< std::string > refLabels{"first", "second"};
        /* demonstrating cast to and from ref and reference_wrapper */
        for (auto& l : ls){
          REQUIRE(TRUE == refLabels.count(l));
        }
        for (auto& l : refLabels){
          REQUIRE(TRUE == ls.count(l));
        }

        /* comparing for equality  between reference wrapper and strings */
        std::equal(refLabels.begin(), refLabels.end(), ls.begin(), ls.end(),
                   std::equal_to<std::string>() ); 

        LOG(INFO) << "Test " <<
          ++testNumber << ": [labels] No Errors Expected";
        ls = fscr.labels();
        REQUIRE(2 == ls.size());
        /* demonstrating cast to and from ref and reference_wrapper */
        for (auto& l : ls){
          REQUIRE(TRUE == refLabels.count(l));
        }
        for (auto& l : refLabels){
          REQUIRE(TRUE == ls.count(l));
        }
        
        LOG(INFO) << "Test " <<
          ++testNumber << ": [data] No Errors Expected";
        REQUIRE(&vr1 == &(fs.data("first")));
        REQUIRE(&vr2 == &(fs.data("second")));
        LOG(INFO) << "Test " <<
          ++testNumber << ": [data] Errors Expected";
        REQUIRE_THROWS(fs.data("third"));

        LOG(INFO) << "Test " <<
          ++testNumber << ": [data] No Errors Expected";
        REQUIRE(&vr1 == &(fscr.data("first")));
        REQUIRE(&vr2 == &(fscr.data("second")));
        LOG(INFO) << "Test " <<
          ++testNumber << ": [data] Errors Expected";
        REQUIRE_THROWS(fscr.data("third"));
        
        LOG(INFO) << "Test " <<
          ++testNumber << ": [form] No Errors Expected";
        REQUIRE(tsr1 == fs.form("first").stamp);
        REQUIRE(tsr2 == fs.form("second").stamp);
        LOG(INFO) << "Test " <<
          ++testNumber << ": [form] Errors Expected";
        REQUIRE_THROWS(fs.form("third"));

        LOG(INFO) << "Test " <<
          ++testNumber << ": [form] No Errors Expected";
        REQUIRE(tsr1 == fscr.form("first").stamp);
        REQUIRE(tsr2 == fscr.form("second").stamp);
        LOG(INFO) << "Test " <<
          ++testNumber << ": [form] Errors Expected";
        REQUIRE_THROWS(fs.form("third"));

        v = {7,8,9};
        upv = std::make_unique< std::vector<int> >(std::move(v));
        label = "third";
        stamp = time(nullptr);
        
        LOG(INFO) << "Test " <<
          ++testNumber << ": [insert] No Errors Expected";
        REQUIRE_NOTHROW(fs.insert( std::move(upv),
                                   label,
                                   stamp,
                                   fs.form("second") ) );

        v = {0,1,2};
        upv = std::make_unique< std::vector<int> >(std::move(v));
        label = "third";
        stamp = time(nullptr);
        
        LOG(INFO) << "Test " <<
          ++testNumber << ": [insert] Errors Expected";
        REQUIRE_THROWS(fs.insert( std::move(upv),
                                  label,
                                  stamp ) );

        LOG(INFO) << "Test " <<
          ++testNumber << ": [insert] No Errors Expected";
        refLabels.insert("third");
        for (auto& l : fs.labels()){
          REQUIRE(TRUE == refLabels.count(l));
        }

        LOG(INFO) << "Test " <<
          ++testNumber << ": [begin/end] No Errors Expected";
        for (auto& form : fs){
          REQUIRE(TRUE == refLabels.count(form.label));
        }

        LOG(INFO) << "Test " <<
          ++testNumber << ": [begin/end] No Errors Expected";
        for (auto formit = fs.begin();
             formit != fs.end();
             ++formit){
          REQUIRE(TRUE == refLabels.count(formit->label));
        }

        LOG(INFO) << "Test " <<
          ++testNumber << ": [cbegin/cend] No Errors Expected";
        for (auto formit = fs.cbegin();
             formit != fs.cend();
             ++formit){
          REQUIRE(TRUE == refLabels.count(formit->label));
        }

        LOG(INFO) << "Test " <<
          ++testNumber << ": [rbegin/rend] No Errors Expected";
        for (auto formit = fs.rbegin();
             formit != fs.rend();
             ++formit){
          REQUIRE(TRUE == refLabels.count(formit->label));
        }

        LOG(INFO) << "Test " <<
          ++testNumber << ": [crbegin/crend] No Errors Expected";
        for (auto formit = fs.crbegin();
             formit != fs.crend();
             ++formit){
          REQUIRE(TRUE == refLabels.count(formit->label));
        }

        auto returnCheck0 =
          [](){
          auto t = std::set<nuclearData::API::Form< std::vector<int> > >();
          nuclearData::API::Forms< std::vector<int> > foo( std::move(t) );
          return std::move(foo);
        };

        auto moveCheck0 =
          [](nuclearData::API::Forms< std::vector<int> >&& foo){
          return std::move(foo);
        };

      }
    }
  }
}
