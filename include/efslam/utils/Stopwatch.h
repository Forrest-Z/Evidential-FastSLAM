/*
 * Software License Agreement (BSD License)
 *
 *  Evidential FastSLAM - An evidential approach to SLAM
 *  Copyright (c) 2013-2016, Joachim Clemens, Thomas Reineking, Tobias Kluth
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither the name of Evidential FastSLAM nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 *  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 *  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 *  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef EFS_STOPWATCH_H_
#define EFS_STOPWATCH_H_

#include <chrono>

#include "Log.h"

namespace efs {

class Stopwatch {
public:
	using clock 		= std::chrono::high_resolution_clock;
	using time_point	= clock::time_point;
	using milliseconds	= std::chrono::milliseconds;

	inline					Stopwatch();

	inline	time_point		now() const noexcept;
	inline	void			reset( const time_point &time ) noexcept;
	inline	void			reset() noexcept;

	inline	milliseconds	timePast( const time_point &time ) const noexcept;
	inline	milliseconds	timePast() const noexcept;

protected:
	time_point m_startTime;
};


std::ostream& operator<<( std::ostream& ostr, const Stopwatch::milliseconds &ms ){
    return ostr << BOLD << ms.count() / 1000.0 << "s" NORMAL;
}

} /* namespace efs */

#include "Stopwatch.hpp"

#endif /* EFS_STOPWATCH_H_ */