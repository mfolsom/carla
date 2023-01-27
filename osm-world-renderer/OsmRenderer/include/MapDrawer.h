#ifndef MAP_DRAWE_H
#define MAP_DRAWE_H

#include <vector>
#include <string>

#include <osmscout/GeoCoord.h>
#include <osmscout/Database.h>
#include <osmscoutmap/MapService.h>
#include <osmscout/BasemapDatabase.h>

using namespace std;

class MapDrawer
{
public:
    MapDrawer(vector<string> Args);

    void Draw(osmscout::GeoCoord Coords, double ZoomValue);

private:
    // Arguments
    string DataBasePath;
    string StyleSheetPath;
    int Size;
    //size_t Latitude;
    //size_t Longitude;
    //size_t Zoom;

    // Entities
    osmscout::DatabaseParameter DbParameter;
    osmscout::DatabaseRef Database;
    osmscout::MapServiceRef MapService;
    osmscout::StyleConfigRef StyleSheet;

    osmscout::MercatorProjection Projection;
    osmscout::MapData MapData;
    osmscout::MapParameter DrawParameter;
    osmscout::AreaSearchParameter SearchParameter;
    //GeoCoord CenterCoords;

    void LoadDatabaseData();
    void SetDrawParameters();

    void DrawMap();
     
};

#endif