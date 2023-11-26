#include <iostream>

#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <StlAPI_Writer.hxx>

int main(int, char**){
    BRepPrimAPI_MakeBox box(gp_Pnt{0,0,0}, 20, 20, 20);
    box.Build();
    TopoDS_Solid mySolid = box.Solid();

    BRepMesh_IncrementalMesh mesh {mySolid, 2};

    auto shape = mesh.Shape();

    StlAPI_Writer writer;
    writer.Write(shape, "test.stl");

    std::cout << "Hello, from Shoe_bottom!\n";
}
