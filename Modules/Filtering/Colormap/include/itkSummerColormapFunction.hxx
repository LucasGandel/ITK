/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkSummerColormapFunction_hxx
#define itkSummerColormapFunction_hxx

#include "itkSummerColormapFunction.h"

namespace itk
{
namespace Function
{
template< typename TScalar, typename TRGBPixel >
typename SummerColormapFunction< TScalar, TRGBPixel >::RGBPixelType
SummerColormapFunction< TScalar, TRGBPixel >
::operator()(const TScalar & v) const
{
  // Map the input scalar between [0, 1].
  RealType value = this->RescaleInputValue(v);

  // Apply the color mapping.
  RealType red = value;

  RealType green = 0.5 * value + 0.5;

  RealType blue = 0.4;

  // Set the rgb components after rescaling the values.
  RGBPixelType pixel;
  NumericTraits<TRGBPixel>::SetLength(pixel, 3);

  pixel[0] = this->RescaleRGBComponentValue(red);
  pixel[1] = this->RescaleRGBComponentValue(green);
  pixel[2] = this->RescaleRGBComponentValue(blue);

  return pixel;
}
} // end namespace Function
} // end namespace itk

#endif