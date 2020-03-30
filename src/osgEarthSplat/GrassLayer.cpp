/* -*-c++-*- */
/* osgEarth - Geospatial SDK for OpenSceneGraph
* Copyright 2008-2012 Pelican Mapping
* http://osgearth.org
*
* osgEarth is free software; you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>
*/
#include "GrassLayer"
#include "SplatShaders"

#define LC "[GrassLayer] " << getName() << ": "

using namespace osgEarth::Splat;

REGISTER_OSGEARTH_LAYER(grass, GrassLayer);

Config
GrassLayer::Options::getConfig() const
{
    Config conf = GroundCoverLayer::Options::getConfig();
    return conf;
}

void
GrassLayer::Options::fromConfig(const Config& conf)
{
    //nop
}

void
GrassLayer::init()
{
    GroundCoverLayer::init();

    if (!options().lod().isSet())
        options().lod().init(19u);
}

void
GrassLayer::loadShaders(VirtualProgram* vp, const osgDB::Options* options) const
{
    GroundCoverShaders s;
    s.load(vp, s.Grass_VS, options);
}
