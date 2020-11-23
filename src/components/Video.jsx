import React from "react";

import "./Video.css";

export default function Video() {
  return (
    <div className="wrapper">
      <div className="video">
        <div className='video-container'><iframe src='https://www.youtube.com/embed/gRsOhXZSqIU' frameBorder='0' allowFullScreen></iframe></div>
      </div>
    </div>
  );
}
