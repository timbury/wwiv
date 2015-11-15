/**************************************************************************/
/*                                                                        */
/*                          WWIV Version 5.0x                             */
/*             Copyright (C)2014-2015 WWIV Software Services              */
/*                                                                        */
/*    Licensed  under the  Apache License, Version  2.0 (the "License");  */
/*    you may not use this  file  except in compliance with the License.  */
/*    You may obtain a copy of the License at                             */
/*                                                                        */
/*                http://www.apache.org/licenses/LICENSE-2.0              */
/*                                                                        */
/*    Unless  required  by  applicable  law  or agreed to  in  writing,   */
/*    software  distributed  under  the  License  is  distributed on an   */
/*    "AS IS"  BASIS, WITHOUT  WARRANTIES  OR  CONDITIONS OF ANY  KIND,   */
/*    either  express  or implied.  See  the  License for  the specific   */
/*    language governing permissions and limitations under the License.   */
/**************************************************************************/
#ifndef __INCLUDED_NETORKB_CONTACT_H__
#define __INCLUDED_NETORKB_CONTACT_H__

#include <initializer_list>
#include <map>
#include <string>
#include <vector>

#include "sdk/net.h"

namespace wwiv {
namespace net {

  
class Contact {
 public:
  explicit Contact(const std::string& network_dir);
  // VisibleForTesting
  Contact(std::initializer_list<net_contact_rec> l);
  virtual ~Contact();

  bool IsInitialized() const { return initialized_; }
  // returns a mutable net_contact_rec for system number "node"
  net_contact_rec* contact_rec_for(int node);
  std::string ToString() const;

 private:
   std::vector<net_contact_rec> contacts_;
   bool initialized_;
   std::string network_dir_;
};


}  // namespace net
}  // namespace wwiv

#endif  // __INCLUDED_NETORKB_CONTACT_H__