//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
#ifndef building_layouts_h
#define building_layouts_h

private mapping BuildingLayouts = ([ 
    "1x1":([
        "type 1": ([
            "ascii": ({ "+-+", "| |", "+-+" }),
            "unicode": ({ "\xe2\x94\x8e\xe2\x8b\x82\xe2\x94\x92",
                "\xe2\x94\x83\xe2\x8b\x83\xe2\x94\x83",
                "\xe2\x94\x97\xe2\x95\xa7\xe2\x94\x9b" })
        ]),
        "type 2": ([
            "ascii": ({ "+-+", "| |", "+-+" }),
            "unicode": ({ "\xe2\x94\x8e\xe2\x95\x90\xe2\x94\x92",
                "\xe2\x94\x83\xe2\x96\xaf\xe2\x94\x83",
                "\xe2\x94\x97\xe2\x95\x90\xe2\x94\x9b" })
        ]),
    ])
]);

#endif
