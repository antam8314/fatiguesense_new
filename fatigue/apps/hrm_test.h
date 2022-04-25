/**************************************************************************//**
 * @file hrm_test.h
 * @brief
 * @version 1.0.0
*******************************************************************************
* # License
*
*******************************************************************************
*
******************************************************************************/

#ifndef FATIGUE_APPS_HRM_TEST_H_
#define FATIGUE_APPS_HRM_TEST_H_

#endif /* FATIGUE_APPS_HRM_TEST_H_ */

// Gamer 3 data
//int TEST_PPG_LENGTH = 101;
//uint16_t testPPG[] = {421, 429, 432, 427, 430, 433, 427, 430, 433, 430, 431, 435, 432, 435, 450, 477, 493, 492, 496, 501, 501, 500, 503, 504, 502, 514, 521, 520, 529, 537, 535, 545, 554, 552, 557, 561, 554, 556, 559, 558, 555, 560, 562, 552, 556, 555, 541, 538, 534, 523, 523, 535, 553, 557, 544, 544, 539, 523, 519, 517, 507, 501, 500, 496, 491, 491, 488, 482, 482, 482, 471, 475, 477, 468, 466, 464, 455, 453, 453, 448, 444, 447, 447, 440, 444, 446, 439, 443, 445, 440, 441, 455, 471, 475, 462, 459, 453, 435, 426, 420, 408};

//int TEST_PPG_LENGTH = 60;
//uint16_t testPPG[] = {432, 435, 450, 477, 493, 492, 496, 501, 501, 500, 503, 504, 502, 514, 521, 520, 529, 537, 535, 545, 554, 552, 557, 561, 554, 556, 559, 558, 555, 560, 562, 552, 556, 555, 541, 538, 534, 519, 517, 507, 501, 500, 496, 491, 491, 488, 482, 482, 482, 471, 475, 477, 468, 466, 464, 455, 453, 453, 448, 444};

int TEST_PPG_LENGTH = 404;
uint16_t testPPG[] = {413, 421, 427, 428, 441, 453, 455, 467, 489, 509, 516, 513, 521, 522, 514, 517, 518, 514, 520, 527, 523, 528, 536, 533, 537, 541, 542, 536, 541, 542, 534, 535, 535, 525, 526, 526, 519, 512, 510, 503, 505, 510, 512, 507, 514, 517, 506, 501, 512, 522, 519, 506, 503, 497, 483, 480, 478, 467, 469, 471, 463, 464, 468, 462, 463, 465, 464, 458, 458, 457, 448, 449, 448, 441, 442, 444, 438, 437, 439, 435, 435, 439, 438, 434, 442, 461, 473, 466, 462, 458, 450, 443, 443, 439, 432, 434, 433, 421, 418, 415, 410, 410, 413, 408, 413, 421, 425, 428, 439, 447, 450, 457, 465, 465, 478, 490, 495, 503, 513, 512, 522, 532, 537, 536, 553, 573, 586, 578, 578, 576, 569, 563, 563, 562, 556, 556, 554, 544, 546, 546, 541, 542, 546, 538, 540, 543, 541, 533, 529, 521, 513, 519, 520, 514, 516, 518, 508, 508, 508, 498, 497, 510, 519, 516, 501, 498, 494, 482, 480, 480, 474, 467, 464, 460, 455, 457, 457, 449, 453, 455, 447, 450, 450, 442, 444, 447, 441, 442, 445, 444, 440, 443, 444, 438, 443, 444, 434, 431, 430, 423, 428, 442, 461, 468, 459, 457, 452, 439, 436, 437, 428, 430, 435, 436, 438, 448, 453, 455, 467, 476, 475, 487, 497, 499, 511, 523, 526, 539, 553, 555, 565, 575, 580, 577, 585, 590, 582, 583, 600, 614, 613, 603, 600, 596, 580, 580, 575, 560, 555, 552, 542, 542, 543, 539, 539, 543, 543, 540, 540, 538, 532, 528, 521, 506, 508, 511, 504, 506, 507, 499, 498, 498, 495, 486, 490, 506, 513, 507, 500, 497, 490, 480, 472, 464, 455, 460, 463, 456, 459, 461, 452, 455, 456, 451, 447, 448, 444, 436, 430, 427, 421, 429, 432, 427, 430, 433, 427, 430, 433, 430, 431, 435, 432, 435, 450, 477, 493, 492, 496, 501, 501, 500, 503, 504, 502, 514, 521, 520, 529, 537, 535, 545, 554, 552, 557, 561, 554, 556, 559, 558, 555, 560, 562, 552, 556, 555, 541, 538, 534, 523, 523, 535, 553, 557, 544, 544, 539, 523, 519, 517, 507, 501, 500, 496, 491, 491, 488, 482, 482, 482, 471, 475, 477, 468, 466, 464, 455, 453, 453, 448, 444, 447, 447, 440, 444, 446, 439, 443, 445, 440, 441, 455, 471, 475, 462, 459, 453, 435, 426, 420, 408, 405, 405, 399};

//int TEST_PPG_LENGTH = 720;
//uint16_t testPPG[] = {413, 421, 427, 428, 441, 453, 455, 467, 489, 509, 516, 513, 521, 522, 514, 517, 518, 514, 520, 527, 523, 528, 536, 533, 537, 541, 542, 536, 541, 542, 534, 535, 535, 525, 526, 526, 519, 512, 510, 503, 505, 510, 512, 507, 514, 517, 506, 501, 512, 522, 519, 506, 503, 497, 483, 480, 478, 467, 469, 471, 463, 464, 468, 462, 463, 465, 464, 458, 458, 457, 448, 449, 448, 441, 442, 444, 438, 437, 439, 435, 435, 439, 438, 434, 442, 461, 473, 466, 462, 458, 450, 443, 443, 439, 432, 434, 433, 421, 418, 415, 410, 410, 413, 408, 413, 421, 425, 428, 439, 447, 450, 457, 465, 465, 478, 490, 495, 503, 513, 512, 522, 532, 537, 536, 553, 573, 586, 578, 578, 576, 569, 563, 563, 562, 556, 556, 554, 544, 546, 546, 541, 542, 546, 538, 540, 543, 541, 533, 529, 521, 513, 519, 520, 514, 516, 518, 508, 508, 508, 498, 497, 510, 519, 516, 501, 498, 494, 482, 480, 480, 474, 467, 464, 460, 455, 457, 457, 449, 453, 455, 447, 450, 450, 442, 444, 447, 441, 442, 445, 444, 440, 443, 444, 438, 443, 444, 434, 431, 430, 423, 428, 442, 461, 468, 459, 457, 452, 439, 436, 437, 428, 430, 435, 436, 438, 448, 453, 455, 467, 476, 475, 487, 497, 499, 511, 523, 526, 539, 553, 555, 565, 575, 580, 577, 585, 590, 582, 583, 600, 614, 613, 603, 600, 596, 580, 580, 575, 560, 555, 552, 542, 542, 543, 539, 539, 543, 543, 540, 540, 538, 532, 528, 521, 506, 508, 511, 504, 506, 507, 499, 498, 498, 495, 486, 490, 506, 513, 507, 500, 497, 490, 480, 472, 464, 455, 460, 463, 456, 459, 461, 452, 455, 456, 451, 447, 448, 444, 436, 430, 427, 421, 429, 432, 427, 430, 433, 427, 430, 433, 430, 431, 435, 432, 435, 450, 477, 493, 492, 496, 501, 501, 500, 503, 504, 502, 514, 521, 520, 529, 537, 535, 545, 554, 552, 557, 561, 554, 556, 559, 558, 555, 560, 562, 552, 556, 555, 541, 538, 534, 523, 523, 535, 553, 557, 544, 544, 539, 523, 519, 517, 507, 501, 500, 496, 491, 491, 488, 482, 482, 482, 471, 475, 477, 468, 466, 464, 455, 453, 453, 448, 444, 447, 447, 440, 444, 446, 439, 443, 445, 440, 441, 455, 471, 475, 462, 459, 453, 435, 426, 420, 408, 405, 405, 399, 402, 411, 416, 414, 421, 424, 419, 426, 432, 427, 432, 438, 436, 444, 454, 455, 465, 478, 486, 490, 502, 512, 511, 525, 550, 569, 573, 570, 568, 566, 555, 560, 562, 553, 558, 559, 552, 555, 557, 548, 548, 550, 547, 539, 535, 530, 521, 528, 531, 524, 529, 531, 522, 523, 523, 516, 510, 510, 505, 500, 498, 495, 485, 489, 506, 518, 511, 504, 497, 488, 476, 474, 470, 458, 456, 455, 445, 439, 436, 427, 430, 436, 436, 433, 433, 430, 425, 432, 436, 432, 433, 435, 425, 424, 424, 417, 420, 426, 423, 424, 435, 455, 465, 458, 453, 448, 436, 429, 425, 421, 414, 419, 423, 421, 429, 438, 438, 451, 464, 467, 476, 488, 489, 493, 499, 502, 501, 506, 511, 507, 512, 517, 513, 521, 527, 523, 523, 535, 551, 553, 540, 536, 530, 516, 509, 506, 496, 498, 501, 502, 500, 503, 503, 496, 496, 495, 485, 490, 492, 483, 483, 485, 476, 476, 477, 474, 469, 467, 464, 454, 455, 454, 445, 447, 448, 440, 442, 450, 465, 468, 456, 451, 442, 429, 425, 425, 418, 422, 425, 423, 417, 415, 411, 404, 399, 399, 394, 400, 406, 407, 413, 421, 420, 425, 432, 433, 430, 432, 429, 426, 427, 428, 422, 424, 442, 460, 466, 466, 467, 469, 462, 468, 471, 472, 477, 484, 482, 491, 501, 501, 509, 521, 525, 529, 537, 543, 536, 541, 542, 533, 533, 534, 526, 519, 514, 503, 502, 508, 504, 509, 514, 517, 509, 513, 530, 542, 539, 530, 522, 513, 495, 492, 485, 473, 472, 472, 462, 464, 466, 460, 455, 457, 451, 445, 441, 439, 435, 437, 437, 435, 435, 439, 432, 437, 440, 438, 438, 443, 436, 435, 436, 452, 458, 450, 440, 435, 424, 420, 420, 420, 418, 422, 422, 419, 422, 424, 417, 422, 425, 419, 419, 421, 414, 416, 420, 420};

// Gamer 1 data
//int TEST_PPG_LENGTH = 675;
//uint16_t testPPG[] = {405, 406, 406, 410, 413, 419, 424, 433, 440, 451, 459, 469, 476, 485, 491, 498, 501, 506, 508, 512, 513, 515, 515, 517, 516, 516, 513, 512, 508, 506, 501, 498, 493, 490, 485, 483, 478, 476, 473, 472, 469, 468, 466, 465, 463, 462, 459, 458, 456, 455, 452, 451, 448, 447, 444, 442, 438, 436, 433, 431, 428, 426, 423, 422, 419, 419, 417, 417, 416, 417, 416, 417, 417, 418, 418, 418, 417, 417, 416, 416, 415, 415, 413, 413, 412, 412, 411, 411, 409, 410, 408, 409, 408, 408, 407, 407, 405, 406, 405, 405, 404, 405, 404, 405, 404, 405, 404, 404, 403, 404, 403, 405, 406, 410, 415, 423, 430, 440, 450, 462, 473, 485, 494, 504, 512, 519, 523, 529, 531, 535, 536, 538, 538, 539, 539, 540, 539, 540, 539, 539, 537, 536, 534, 533, 530, 529, 527, 526, 525, 525, 523, 523, 522, 522, 521, 521, 519, 518, 517, 516, 514, 513, 511, 510, 508, 506, 503, 502, 499, 498, 496, 494, 491, 489, 486, 484, 482, 480, 478, 477, 475, 474, 473, 472, 471, 470, 469, 468, 468, 467, 467, 466, 466, 466, 465, 464, 463, 463, 462, 461, 460, 460, 459, 458, 458, 458, 458, 457, 457, 458, 458, 458, 459, 459, 459, 459, 458, 458, 458, 458, 458, 459, 462, 466, 472, 479, 487, 495, 505, 514, 522, 530, 537, 542, 547, 550, 552, 554, 555, 555, 555, 553, 553, 551, 550, 548, 545, 542, 539, 536, 534, 531, 529, 527, 526, 524, 523, 522, 522, 521, 521, 520, 520, 519, 519, 517, 516, 513, 513, 511, 510, 507, 505, 502, 501, 497, 494, 490, 488, 485, 483, 480, 478, 476, 474, 472, 470, 468, 467, 465, 464, 461, 461, 459, 458, 456, 455, 453, 453, 451, 450, 449, 448, 447, 447, 445, 445, 443, 444, 442, 443, 442, 443, 442, 443, 441, 442, 440, 442, 442, 444, 446, 450, 455, 463, 469, 478, 486, 495, 502, 510, 515, 522, 526, 531, 533, 537, 537, 539, 538, 539, 537, 537, 535, 535, 532, 530, 526, 524, 519, 516, 511, 508, 503, 501, 497, 495, 492, 492, 489, 489, 487, 487, 484, 483, 480, 479, 475, 473, 469, 467, 463, 461, 456, 454, 449, 446, 442, 440, 436, 434, 431, 430, 426, 426, 423, 422, 420, 420, 417, 417, 416, 416, 415, 416, 415, 416, 415, 416, 416, 417, 417, 418, 418, 419, 418, 420, 419, 421, 420, 421, 421, 423, 423, 425, 425, 427, 429, 435, 439, 447, 454, 464, 472, 482, 490, 500, 506, 514, 519, 524, 527, 531, 531, 533, 532, 533, 531, 532, 530, 530, 527, 527, 523, 521, 517, 515, 512, 511, 507, 507, 504, 505, 503, 504, 502, 503, 502, 502, 500, 500, 498, 498, 495, 495, 492, 491, 488, 487, 484, 482, 478, 477, 473, 471, 466, 464, 461, 459, 456, 455, 452, 451, 449, 448, 446, 446, 445, 446, 444, 444, 443, 443, 442, 443, 442, 442, 442, 444, 444, 447, 449, 454, 458, 463, 469, 477, 484, 493, 501, 510, 516, 524, 529, 535, 537, 541, 542, 544, 543, 544, 543, 544, 542, 543, 541, 540, 538, 537, 534, 533, 529, 528, 525, 524, 522, 521, 520, 520, 518, 519, 517, 518, 516, 516, 513, 513, 510, 510, 507, 506, 503, 502, 499, 498, 494, 492, 489, 488, 484, 483, 480, 480, 478, 477, 475, 475, 472, 472, 470, 469, 467, 465, 462, 461, 458, 457, 454, 453, 450, 449, 446, 445, 442, 441, 438, 438, 437, 439, 439, 443, 445, 451, 456, 464, 469, 476, 481, 488, 492, 497, 499, 504, 506, 509, 511, 514, 515, 518, 518, 521, 521, 523, 522, 523, 521, 521, 518, 518, 516, 515, 513, 513, 512, 512, 510, 510, 509, 509, 507, 507, 505, 504, 502, 501, 498, 497, 494, 493, 490, 488, 485, 483, 480, 478, 475, 473, 470, 469, 467, 466, 464, 464, 462, 462, 461, 462, 461, 462, 462, 464, 464, 466, 467, 469, 469, 470, 470, 471, 471, 471, 470, 470, 468, 468};