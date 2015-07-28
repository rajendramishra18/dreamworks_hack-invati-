#include "MapLoader.h"
#include "Vector.h"
#include <cstring>
#include <openvdb/openvdb.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

/************************ This loads the map from openVDB.
 You can use the native viewer once you complete this.
 There are comments for each snippet of code.
 Hint: http://www.openvdb.org/documentation/doxygen/codeExamples.html **************/

bool** MapLoader::loadVDBMap(char* filename) {
	//Initialize the OpenVDB library.
	openvdb::initialize();

	// Create a VDB file object.
	openvdb::io::File file(filename);

	// Open the file. This reads the file header, but not any grids.
	file.open();

	//Loop over all grids in the file an d retrieve a shared pointer to "SDF". Close file
	openvdb::GridBase::Ptr baseGrid;
	for (openvdb::io::File::NameIterator nameIter = file.beginName();
			nameIter != file.endName(); ++nameIter) {
		if (nameIter.gridName() == "SDF") {
			baseGrid = file.readGrid(nameIter.gridName());

		} else {
			std::cout << "skipping grid " << nameIter.gridName() << std::endl;
		}
	}
	file.close();

	//cast the generic grid pointer to a FloatGrid pointer.
	openvdb::FloatGrid::Ptr grid = openvdb::gridPtrCast<openvdb::FloatGrid>(
			baseGrid);

	//Get metadata into strings, see .meta file
	std::string s = grid->metaValue<std::string>("vector_type");

	//Convert strings to numbers

	posStart.x = grid->metaValue<float>("startx");
	posStart.y = grid->metaValue<float>("starty");
	startRadius = grid->metaValue<float>("start_radius");

	posEnd.x = grid->metaValue<float>("endx");
	posEnd.y = grid->metaValue<float>("endy");
	endRadius = grid->metaValue<float>("end_radius");

	x_boundary = grid->metaValue<float>("boundx");
	y_boundary = grid->metaValue<float>("boundy");
	loaded = false;

	// Create the map data - 2D map and SDF arrays. Allocate memory

	//Get an accessor for coordinate-based access to voxels.
	openvdb::FloatGrid::Accessor accessor = grid->getAccessor();

	std::cout << grid->metaCount();
	/* Iterate through SDF array using the accessor to get SDF values.
	 Add true or false to map data according to the SDF value. */
	for (openvdb::FloatGrid::ValueOnCIter iter = grid->cbeginValueOn();
			iter.test(); ++iter) {
		std::cout << "Grid" << iter.getCoord() << " = " << *iter << std::endl;
	}

	//Get values of Vectors posStart and posEnd

	//Change "loaded" flag

	//Return map data array
}

float** MapLoader::getSDF() {

}

MapLoader::MapLoader() {

}

Vec2f MapLoader::getStartPosition() {

}

Vec2f MapLoader::getEndPosition() {

}

unsigned int MapLoader::gety_boundary() {

}

unsigned int MapLoader::getx_boundary() {

}

unsigned int MapLoader::getStartRadius() {

}

unsigned int MapLoader::getEndRadius() {

}

