# TODO
- [ ] Vendor raylib instead of cmake fetch content? Use git submodules?
- [ ] Use raymath.h from raylib in game_math.h?
- [ ] Physics needs a way to query all game objects that might collide with a given object, ideally you'd have a function GetOverlappingObjects(AABB bounds) and get objects that overlap that (it's okay to get objects that don't overlap as long as ALL that do overlap are included), to begin with you might need a way to get all GameObjects that have physics and transform components

