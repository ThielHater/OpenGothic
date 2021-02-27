#include "vobbundle.h"

#include <zenload/zenParser.h>

#include "world/world.h"
#include "utils/versioninfo.h"
#include "resources.h"

VobBundle::VobBundle(World& owner, const std::string& filename) {
  ZenLoad::oCWorldData bundle = Resources::loadVobBundle(filename);
  for(auto& vob:bundle.rootVobs)
    rootVobs.emplace_back(Vob::load(nullptr,owner,std::move(vob),true));
  }

void VobBundle::setObjMatrix(const Tempest::Matrix4x4& obj) {
  for(auto& i:rootVobs)
    i->setLocalTransform(obj);
  }
