//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

// Created: 2021-1-14 for project ds.base

package dsbase.simulations;

import dsbase.INode;

import dsbase.simulations.Link;

//
// A generated network with ring topology.
//
network Ring
{
    parameters:
        @display("bgb=300,300");
        int n = default(10);
        string kind;
    submodules:
        node[6] : <kind> like INode {
            @display("p=,,ring,");
        }
    connections:
        for i=0..n-1 {
            node[i].port++ <--> Link <--> node[(i+1)%n].port++;
        }
}
