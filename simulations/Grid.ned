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
// A generated network with grid topology.
//
network Grid
{
    parameters:
        int columns = default(4);
        int rows = default(4);
        string kind;
    submodules:
        node[columns*rows]: <kind> like INode {
            @display("p=,,matrix,$columns");
            
        }
    connections allowunconnected:
        for i=0..rows-1, for j=0..columns-1 {
            node[i*columns+j].port++ <--> Link <--> node[(i+1)*columns+j].port++ if i!=rows-1;
            node[i*columns+j].port++ <--> Link <--> node[i*columns+j+1].port++ if j!=columns-1;
        }
}
